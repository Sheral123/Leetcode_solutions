//KADANE ALGORITHM => WE WILL NOT MAKE THE SUM = 0 UNTILL ITS NOT NEGATIVE AS IT MIGHT GET A + VALUE 
//ADDITION WHICH IS BIGGER THAN PREVOUS ANSWER


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans= INT_MIN;
        int sum=0;
        for(auto a:nums){
            sum+=a;
            ans = max(sum,ans);
            if(sum<0) sum=0;
        }
        return ans;
    }
};

