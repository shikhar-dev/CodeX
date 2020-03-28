import os
import urllib.request as urlReq
import json

# To make extension for source code files
EXT = {'C++': 'cpp', 'C': 'c', 'Java': 'java', 'Python': 'py', 'Delphi': 'dpr', 'FPC': 'pas', 'C#': 'cs'}
EXT_keys = EXT.keys()

replacer = {'&quot;': '\"', '&gt;': '>', '&lt;': '<', '&amp;': '&', "&apos;": "'"}
keys = replacer.keys()

# Your codeforces handle/username
HANDLE = 'Your_dad'
# Maximum number of submissions to fetch ie set according to max attempts to solve a problem
MAX_THRESHOLD_FOR_AC = 20
# User.status codeforces api request url
USER_STATUS_REQ_URL = 'https://codeforces.com/api/user.status?handle={handle}&from=1&count={count}'
# Url to get submission code for user
SUBMISSION_URL = 'https://codeforces.com/contest/{contestId}/submission/{submissionId}'
# Tag where the source code begins
SOURCE_CODE_BEGIN = '<pre class="prettyprint program-source" style="padding: 0.5em;">'
# Used to skip to code tag
START_POINT = 17000
# Path to current directory
BASE_DIR_NAME = os.path.dirname(__file__)

def get_ext(comp_lang):
    if 'C++' in comp_lang:
        return 'cpp'
    for key in EXT_keys:
        if key in comp_lang:
            return EXT[key]
    return ""

def parse(source_code):
    for key in keys:
        source_code = source_code.replace(key, replacer[key])
    return source_code


with urlReq.urlopen(USER_STATUS_REQ_URL.format(handle=HANDLE, count=MAX_THRESHOLD_FOR_AC)) as response:
    htmlResponse = response.read()
    jsonResponse = json.loads(htmlResponse)
    if jsonResponse['status'] == 'OK':
        submissions = jsonResponse['result']
        # Last problem is not solved yet
        if len(submissions) == 0 or submissions[0]['verdict'] != 'OK':
            print('Not AC error')
            exit(0)
        acContestId = submissions[0]['problem']['contestId']
        acProblemIndex = submissions[0]['problem']['index']
        acProblemName = submissions[0]['problem']['name']
        # Contains all submissions for last solved problem
        submissionForProblem = list(filter(lambda sub: sub['problem']['contestId'] == acContestId and sub['problem']['index'] == acProblemIndex, submissions))

        # Creating folder and file for this data
        dirName = str(BASE_DIR_NAME)+'/ContestID_'+str(acContestId)+'/'+acProblemIndex+'_'+acProblemName
        os.makedirs(dirName, exist_ok=True)
        with open(dirName+'/Stats.md','w') as logFile:
            # Writing Stats to File
            statsDirToPrint = {}
            statsDirToPrint['Problem Name'] = str(acProblemName)
            statsDirToPrint['Difficulty'] = str(acProblemIndex)
            statsDirToPrint['Contest Id'] = str(acContestId)
            statsDirToPrint['Problem url'] = 'https://codeforces.com/contest/'+str(acContestId)+'/problem/'+str(acProblemIndex)+'/'
            statsDirToPrint['Problem Tags'] = ' '.join(submissions[0]['problem']['tags'])
            statsDirToPrint['Programming language used'] = submissionForProblem[0]['programmingLanguage']
            statsDirToPrint['Attempts to AC'] = str(len(submissionForProblem))
            statsDirToPrint['Accuracy'] = str(100.00/float(len(submissionForProblem)))+'%'
            statsDirToPrint['Solution Time'] = str(submissionForProblem[0]['timeConsumedMillis'])+' ms'
            logFile.write('# Stats\n')
            for key, val in statsDirToPrint.items():
                logFile.write('## '+key+'\n'+val+'\n')
            logFile.close()
    else:
        print('API error')