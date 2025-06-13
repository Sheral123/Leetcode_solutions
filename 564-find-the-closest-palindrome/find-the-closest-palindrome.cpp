class Solution {
public:
    string nearestPalindromic(string n) {

        int len = n.length();
        long long num = stoll(n);
        vector<long long> candidates;

        candidates.push_back((long long)pow(10,len -1)-1);
        candidates.push_back((long long)pow(10,len)+1);

        long long prefix = stoll(n.substr(0,(len+1)/2));
        for(int i = -1; i<=1; i++){
            string newPrefix = to_string(prefix + i);
            string palin = newPrefix;
            string rev = newPrefix.substr(0, len/2);
            reverse(rev.begin(), rev.end());
            palin += rev;

            candidates.push_back(stoll(palin));
        }

        long long minDiff = LLONG_MAX, res = -1;
        for(long long cand:candidates){
            if(cand == num)continue;
            long long diff = abs(cand - num);
            if(diff < minDiff || (diff == minDiff) && (cand < res)){
                res = cand;
                minDiff = diff;
            }

        }
        return to_string(res);
    }
};