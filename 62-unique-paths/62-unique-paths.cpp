class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for(size_t row = 1; row < m; row++)
        {
            for(size_t col = 1; col < n; col++)
            {
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp.back().back();
    }
};