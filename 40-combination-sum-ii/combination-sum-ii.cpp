class Solution {

    void findCombinations( int start, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> ds){
        if(target == 0){
            ans.push_back(ds);
        }

        for(int i=start ;i<candidates.size();i++){
            if(i>start && candidates[i]== candidates[i-1]) continue;

            if(candidates[i]>target) break;

            ds.push_back(candidates[i]);
            findCombinations(i+1, target-candidates[i], candidates, ans, ds);
            ds.pop_back();
        }
    }


public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        sort(candidates.begin(),candidates.end());
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};