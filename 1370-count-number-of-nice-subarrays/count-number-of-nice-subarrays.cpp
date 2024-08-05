class Solution {
public:
    int numberOfSubarray(vector<int>& nums, int k) {
        int l=0, r=0, sum=0, cnt=0;

        int n = nums.size();
        while(r<n){
            sum = sum + nums[r]%2;
            while(sum > k){
                sum = sum - nums[l]%2;
                l++;
            }
            cnt = cnt + (r-l +1);
            r++;
        }
        return cnt;
        
    }


    int numberOfSubarrays(vector<int>& nums, int k){
        return numberOfSubarray(nums,k) - numberOfSubarray(nums,k-1);
    }

};