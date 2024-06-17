class Solution {
public:
    int majorityElement(vector<int>& nums) {

       /* int v = nums.size();

        unordered_map <int,int> m;

        for(int i=0; i<v; i++){
            m[nums[i]]++;
        }

        for(auto it:m){
            if(it.second > v/2) return it.first;
        }

        return -1;*/

        int n =nums.size();
        int el;
        int count=0;

        for(int i=0; i< n; i++){
            if(count == 0){
                el = nums[i];
                count = 1;
            }
            else if(el == nums[i]){
                count++;
            }
            else count--;
        }

        int cnt1 =0;
        for(int i =0 ; i<n; i++){
            if(nums[i]== el) cnt1++;
        }

        if(cnt1 > (n/2)) return el;

        return -1;
    }
};