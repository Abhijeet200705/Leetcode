class Solution {
public:
    void findCombinations(int i, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds){
        int n=candidates.size();
        if(i==n){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            findCombinations(i, target-candidates[i], candidates, ans, ds);
            ds.pop_back();

        }
        
        findCombinations(i+1, target, candidates, ans, ds);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        findCombinations(0, target, candidates, ans, ds);
        return ans;
        
    }
};