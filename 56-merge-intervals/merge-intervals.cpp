class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        for(int i=0 ; i<n ; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(ans.empty() || start > ans.back()[1]){
                ans.push_back({start,end});
            }

            else{
                ans.back()[1] = max(end,ans.back()[1] );
            }

        }
        return ans;
    }
};