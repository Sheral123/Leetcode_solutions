class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxque, minque;
        int n = nums.size();
        int left = 0, res = 0;

        for(int right = 0; right<n; right++){

            while(!maxque.empty() && nums[right] > maxque.back()){
                maxque.pop_back();
            }
            maxque.push_back(nums[right]);

            while(!minque.empty() && nums[right] < minque.back()){
                minque.pop_back();
            }
            minque.push_back(nums[right]);

            while(maxque.front() - minque.front() > limit){
                if(nums[left]==maxque.front())maxque.pop_front();
                if(nums[left]==minque.front())minque.pop_front();
                left++;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};