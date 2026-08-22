class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size());
        prefixSum[0]=nums[0];

        for(int i=1;i<nums.size();i++){
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }
        unordered_map<int,int> mp;
        int count=0;
        for(int i=0;i<prefixSum.size();i++){
            if(prefixSum[i]==k){
                count++;
            }
            if(mp.find(prefixSum[i]-k)!=mp.end()){
                count+=mp[prefixSum[i]-k];
            }
            mp[prefixSum[i]]++;
        }
        return count;
    }
};