class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;
        unordered_map <int,int> m;
        int v = nums.size();

        for(int i=0; i<v; i++){
            m[nums[i]]++;
        }

        for(auto it:m){
            if(it.second > v/3) ans.push_back(it.first);
        }

        return ans;
        
    }
};