class Solution {
public:
    int f(int idx, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(idx == 0) return (nums[0]== target);
        if(dp[idx][target] != -1 ) return dp[idx][target];

        bool notTake = f(idx-1, target, nums, dp);
        bool Take = false;
        if(target>= nums[idx]){
            Take = f(idx-1, target - nums[idx], nums, dp);
        }
        return dp[idx][target]=(Take or notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum % 2 !=0) return false;
        else{
            int s = sum/2;
            vector<vector<int>> dp(n, vector<int>(s+1, -1));
            return f(n-1, s, nums, dp);
        }
    }
};