class Solution {
public:

    int f(int n, int amount, vector<int> &coins, vector<vector<long long>> &dp){
        if(n == 0){
            return (amount % coins[0] == 0) ?1 :0;
        }
        if(dp[n][amount] != -1) return dp[n][amount];
        long long notPick = f(n-1, amount, coins, dp);
        long long pick = 0;
        if(coins[n]<=amount){
            pick = f(n, amount - coins[n], coins, dp);
        }
        return dp[n][amount] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (n == 0) return (amount == 0) ? 1 : 0;
        vector<vector<long long>> dp(n, vector<long long> (amount+1, -1));
        return f(n-1, amount, coins, dp);
        
    }
};