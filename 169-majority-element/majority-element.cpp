class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(auto i:nums){
            mp[i]++;
        }

        for(auto j : mp){
            if(j.second>n/2){
                return j.first;
            }
        }
        return 0;
    }
};