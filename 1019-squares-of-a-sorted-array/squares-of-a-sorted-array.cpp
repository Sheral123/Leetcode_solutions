class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        int idx = n-1;
        int left = 0, right= n-1;
        vector<int> res(n);

        while(left<=right){
            int leftsq = nums[left]*nums[left];
            int rightsq = nums[right]*nums[right];

            if(leftsq>rightsq){
                res[idx] = leftsq;
                idx--;
                left++;
            }
            else{
                res[idx] = rightsq;
                idx--;
                right--;
            }
        }
        return res;
    }
};