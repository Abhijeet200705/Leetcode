class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        long long mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                long long cnt = st.size();
                ans = (ans + cnt * cnt) % mod;
            }            
        }
        return ans;

    }
};