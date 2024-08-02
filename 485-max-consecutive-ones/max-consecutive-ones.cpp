class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx = 0;
        int cmp=0;
        int n = nums.size();
        for(int i =0; i<n;i++){
            if(nums[i] == 0) {
                mx = 0;
            }    
            else{
                mx++;  
            }
            cmp = max(cmp,mx);
        }
        return cmp;
    }
};