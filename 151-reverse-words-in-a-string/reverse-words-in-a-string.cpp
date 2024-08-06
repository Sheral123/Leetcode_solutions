/*  TWO POINTER METHOD USING EXTRA SPACE */

class Solution {
public:
    string reverseWords(string s) {
        int i=0, j, n=s.size();
        string str;
        while(i<n)
        {
            while(i<n && s[i]==' ') i++;
            if(i==n) break;
            j = i+1;
            while(j<n && s[j]!=' ')j++;
            string sub = s.substr(i, j-i);
            if(str.size()==0)str = sub;
            else str = sub + " " + str;
            i = j+1;
        }
        return str;
    }
};