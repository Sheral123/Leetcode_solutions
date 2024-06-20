class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> chars;
        int i=0, j=0, maxsize=0;

        while(j<s.size()){
            while(chars.find(s[j])!= chars.end()){
                chars.erase(s[i]);
                i++;
            }

            maxsize=max(maxsize,j-i+1);
            chars.insert(s[j]);
            j++;
        }

        return maxsize;
        
        
    }
};