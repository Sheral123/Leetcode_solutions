class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3,-1);
        int j=0, n=s.size();
        int cnt=0;
        while(j<n){
            v[s[j]  - 'a'] = j;
            if(v[0]!= -1 && v[1]!= -1 && v[2]!= -1){
                int minimum = min(v[0],v[1]);
                cnt =cnt + min(minimum,v[2]) +1;
            }
            j++;
        }
        return cnt;
        
    }
};