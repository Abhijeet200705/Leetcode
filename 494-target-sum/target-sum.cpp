class Solution {
public:

    int f(int n, vector<int> &nums, int target, vector<vector<int>> &dp, int totalSum){
        if(n == 0){
            return target == 0;
        }
        if(abs(target) > totalSum) return 0;
        if(dp[n][target + totalSum] != -1) return dp[n][target + totalSum];


        int plus = f(n-1, nums, target - nums[n-1], dp, totalSum);
        int minus = f(n-1, nums, target + nums[n-1], dp, totalSum);

        return dp[n][target + totalSum] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        

         int totalSum = 0;

        for(int x : nums) {
            totalSum += x;
        }

        if(abs(target) > totalSum) return 0;

        vector<vector<int>> dp(n+1, vector<int>(2*totalSum+1, -1));

        return f(n, nums, target, dp, totalSum);
    }
};