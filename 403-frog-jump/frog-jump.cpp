class Solution {

    int dp[2001][2001];
    bool solve(vector<int> &stones, int idx, int jump){
        int n=stones.size();

        if(idx<0 || idx>=n) return false;
        if(idx+1==n) return true;
        
        if(dp[idx][jump]!=-1) return dp[idx][jump];

        for(int k=-1;k<=1;k++){
            int nextJump=jump+k;
            if(nextJump<=0) continue;

            int nextPosition = stones[idx]+nextJump;
            auto it = lower_bound(stones.begin(),stones.end(), nextPosition);

            if(it ==stones.end() || *it !=nextPosition) continue;

            int nextIdx = it-stones.begin();
            if(solve(stones, nextIdx, nextJump)) return dp[idx][jump]=true;
        }
        return dp[idx][jump]=false;

    }

public:
    bool canCross(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        return solve(stones, 0, 0);
    }
};