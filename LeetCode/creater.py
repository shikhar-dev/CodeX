import os
import sys

BASE_DIR_NAME = os.path.dirname(__file__)

questionUrl = sys.argv[1]
questionName = questionUrl.split('/')[4]
result = '// Problem URL: ' + questionUrl

with open(BASE_DIR_NAME+'/'+ questionName +'.cpp', 'w') as sourceFile:
    sourceFile.write(result)
    sourceFile.close()