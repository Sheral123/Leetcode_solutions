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
       // vector<int> dp1(nums.size()-1,-1);
        //vector<int> dp2(nums.size()-1,-1);
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
     
        int prev2= nums1[0];
        int prev= nums1[0];
        for(int i=1 ; i<nums1.size();i++){
            int right = nums1[i];
            if(i>1){
                right += prev2;
            }         
            int left = prev;
            prev2 = prev;
            prev = max(left,right);
        }

        int prev3 = nums2[0];
        int prev4= nums2[0];
        for(int i=1 ; i<nums2.size();i++){
            int right = nums2[i];
            if(i>1){
                right += prev3;
            }
            int left = prev4;
            prev3=prev4;
            prev4= max(left,right);
        }
        return max(prev,prev4);
    }
};