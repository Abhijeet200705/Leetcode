class Solution {
public:

    int f(int index, vector<int> &coins, int amount, vector<vector<int>> &dp){
        int n = coins.size();
        if(index == 0) {
            if(amount % coins[index] == 0) return amount/coins[index];
            else return 1e9;

        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int notPick = 0 + f(index - 1, coins, amount, dp);
        int pick = INT_MAX;
        if(coins[index]<=amount){
            pick = 1 + f(index, coins, amount - coins[index], dp);
        }
        return dp[index][amount] = min(pick,notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = f(n-1, coins, amount, dp);

        if(ans >= 1e9) return -1;
        else return ans;
    }
};