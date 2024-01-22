class Solution {
public:
  
    int f(vector<int>& nums,vector<int>& dp, int ind){
        if(ind == 0) return nums[0];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];

        int right = nums[ind] + f(nums,dp, ind - 2);
        int left = f(nums,dp, ind -1);
        
        return dp[ind] = max(left, right);
    }

    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size()-1,-1);
        vector<int> dp2(nums.size()-1,-1);
        vector<int> nums1;
        vector<int> nums2;
        if(nums.size() == 1) return nums[0];
        for(int i=0; i< nums.size(); i++){
            if(i != nums.size()-1){
                nums1.push_back(nums[i]);      
            }
            if(i!=0){
                nums2.push_back(nums[i]);
            }
        }
        int ans1 = f(nums1,dp1,nums1.size()-1);
        int ans2 = f(nums2,dp2,nums2.size()-1);
        cout<<nums1.size();
        cout<<nums2.size();
        return max(ans1,ans2);
    }
};