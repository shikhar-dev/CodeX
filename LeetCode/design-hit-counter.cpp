// Problem URL: https://leetcode.com/problems/design-hit-counter/
class HitCounter {
private:
    vector <int> recordHit;
public:
    HitCounter() {}

    void hit(int timeStamp) {
        recordHit.push_back(timeStamp);
    }

    int getHits(int timeStamp) {
        int l = max(timeStamp-299,1), u = timeStamp + 1;
        vector <int> :: iterator il,iu;
        il = lower_bound(recordHit.begin(),recordHit.end(),l);
        iu = lower_bound(recordHit.begin(),recordHit.end(),u);
        return iu - il;
    }

};