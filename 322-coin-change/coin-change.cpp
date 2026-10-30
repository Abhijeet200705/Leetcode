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
        for(int t=0; t<=amount;t++){
            if(t%coins[0] == 0){
                dp[0][t] = t/coins[0];
            }
            else dp[0][t] = 1e9;

            

        }

        for(int i = 1;i<n;i++){
            for(int t =0;t<=amount;t++){
                int notPick = 0 + dp[i - 1][t];
                int pick = INT_MAX;
                if(coins[i]<=t){
                    pick = 1 + dp[i][t - coins[i]];
                }
                dp[i][t] = min(pick,notPick);

            }
        }


        int ans = dp[n-1] [amount];

        if(ans >= 1e9) return -1;
        else return ans;
    }
};