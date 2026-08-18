class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        for(auto z: mp){
            if(z.second==1){
                return z.first;
            }
        }
        return -1;

    }
};