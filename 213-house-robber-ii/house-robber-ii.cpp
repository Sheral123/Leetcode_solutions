class Solution {
public:
  
    /*int f(vector<int>& nums,vector<int>& dp, int ind){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int right = nums[ind] + f(nums,dp, ind - 2);
        int left = f(nums,dp, ind -1);
        
        return dp[ind] = max(left, right);
    }*/

    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size()-1,-1);
        vector<int> dp2(nums.size()-1,-1);
        vector<int> nums1, nums2;
        if(nums.size() == 1) return nums[0];
        for(int i=0; i< nums.size(); i++){
            if(i != nums.size()-1){
                nums1.push_back(nums[i]);      
            }
            if(i!=0){
                nums2.push_back(nums[i]);
            }
        }
     
        dp1[0] = nums1[0];
        for(int i=1 ; i<nums1.size();i++){
            int right = nums1[i];
            if(i>1){
                right += dp1[i - 2];
            }         
            int left = dp1[i-1];
            dp1[i]= max(left,right);
        }

        dp2[0] = nums2[0];
        for(int i=1 ; i<nums2.size();i++){
            int right = nums2[i];
            if(i>1){
                right += dp2[i - 2];
            }
            int left = dp2[i-1];
            dp2[i]= max(left,right);
        }
        return max(dp1[nums1.size()-1],dp2[nums2.size()-1]);
    }
};