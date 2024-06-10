class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxpro=0, b=0, s=0;
        while(s<prices.size()){
            if(prices[b] < prices[s]){
                int temp=prices[s] - prices[b];
                maxpro=max(maxpro,temp);
            }
            else{
                b=s;
            }
            s++;
        }
        return maxpro;
    }
        
};