class Solution {
public:
    int solveUniquePathsWithObstacles(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(i >= n || j >= m) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == n-1 && j == m-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solveUniquePathsWithObstacles(i+1,j,obstacleGrid,dp);
        int down = solveUniquePathsWithObstacles(i,j+1,obstacleGrid, dp);

        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));

        return solveUniquePathsWithObstacles(0,0,obstacleGrid, dp);
    }
};