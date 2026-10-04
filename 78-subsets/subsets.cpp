class Solution {

void subsets(vector<int> &nums, int i, vector<vector<int>> &subs, vector<int> &sub){
    subs.push_back(sub);
    for(int j=i;j<nums.size();j++){

        sub.push_back(nums[j]);
        subsets(nums, j+1, subs, sub);
        sub.pop_back();

    }
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, subs, sub);
        return subs;
        
    }
};


