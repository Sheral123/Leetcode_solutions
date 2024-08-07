class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int presum =0;
        int cnt=0;
        int n = nums.size();
        mp[0]=1;
        for(int i =0; i<n; i++){
            presum = presum + nums[i];
            int remove = presum - k;
            cnt += mp[remove];
            mp[presum] +=1;
        }
        return cnt;
    }
};