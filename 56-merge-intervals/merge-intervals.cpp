class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Add the first interval
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            // Check if current interval overlaps with last interval
            if (intervals[i][0] <= ans.back()[1]) {
                // Merge
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } 
            else {
                // No overlap
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};