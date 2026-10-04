class Solution {
public:

    void subsets(vector<int> &nums, int i, vector<vector<int>> &subs, vector<int> &sub){
        subs.push_back(sub);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            sub.push_back(nums[j]);
            subsets(nums, j+1, subs, sub);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> subs;
        sort(nums.begin(),nums.end());

        subsets(nums, 0 , subs, sub);
        return subs;
    }
};