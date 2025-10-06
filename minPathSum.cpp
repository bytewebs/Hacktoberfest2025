class Solution {
public:
    int f(int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        const int INF = 1e9;
        if (m < 0 || n < 0) return INF;
        if (m == 0 && n == 0) return grid[0][0];
        if (dp[m][n] != -1) return dp[m][n];
        int up = f(m-1,n,grid,dp);
        int left = f(m,n-1,grid,dp);
        return dp[m][n]=grid[m][n] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};
