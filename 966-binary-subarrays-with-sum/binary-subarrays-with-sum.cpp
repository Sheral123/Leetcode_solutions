class Solution {
public:
    int subarrayLessThanEqualToGoal(vector<int>& nums, int goal) {
        int l=0, r=0, n= nums.size(), cnt=0, sum=0;
        if(goal < 0) return 0;

        while(r<n){
            sum = sum + nums[r];
            while(sum > goal){
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;   
    }

    int numSubarraysWithSum(vector<int>& nums, int goal){
        int a = subarrayLessThanEqualToGoal(nums, goal - 1);
        int b = subarrayLessThanEqualToGoal(nums, goal);
        return b-a;
    }
};