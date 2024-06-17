class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int v = nums.size();

        unordered_map <int,int> m;

        for(int i=0; i<v; i++){
            m[nums[i]]++;
        }

        for(auto it:m){
            if(it.second > v/2) return it.first;
        }

        return -1;
        
    }
};