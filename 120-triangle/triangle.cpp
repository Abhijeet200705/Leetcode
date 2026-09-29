class Solution {

int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    int m = triangle.size();

    if(i == m-1) return triangle[i][j];

    if(dp[i][j] != 1e9) return dp[i][j];

    int down  = f(i+1, j,   triangle, dp);
    int right = f(i+1, j+1, triangle, dp);

    return dp[i][j] = triangle[i][j] + min(down, right);
}

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 1e9));
        return f(0, 0, triangle, dp);
    }
};