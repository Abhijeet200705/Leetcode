class Solution {

int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    int n=matrix.size();
    if(j<0 || j>=n){
        return 1e9;
    }
    

    if(i==n-1) return matrix[i][j];

    if(dp[i][j] != INT_MAX) return dp[i][j];

    int down = f(i+1,j,matrix,dp);
    int left = f(i+1,j-1,matrix,dp);
    int right = f(i+1,j+1,matrix,dp);

    return dp[i][j]=matrix[i][j] + min({down, left, right});
}

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n, vector<int> (m, INT_MAX));

        for(int j=0;j<n;j++){
                ans= min(ans,f(0, j, matrix, dp));
        }

        return ans;
        
    }
};