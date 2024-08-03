class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j =0;
        int maxLen = 0;
        int countZero = 0;
        while(j< nums.size()){
            if(nums[j] == 0) countZero++;

            while(countZero > k){
                if(nums[i] == 0){
                    countZero--;
                }
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};