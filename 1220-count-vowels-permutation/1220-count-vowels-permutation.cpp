class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n, vector<long long>(5, 1));
        int MODE = 1e9+7;

        for(size_t i = 1; i < n; i++)
        {
            int prev = i-1;
            dp[i][0] = dp[prev][1] + dp[prev][2] + dp[prev][4];
            dp[i][0] %= MODE;
            
            dp[i][1] = dp[prev][0] + dp[prev][2];
            dp[i][1] %= MODE;
            
            dp[i][2] = dp[prev][1] + dp[prev][3]; 
            dp[i][2] %= MODE;
            
            dp[i][3] = dp[prev][2];
            dp[i][3] %= MODE;
            
            dp[i][4] = dp[prev][2] + dp[prev][3];
            dp[i][4] %= MODE;
        }
        long long res = 0;
        for(size_t i = 0; i < 5; i++)
        {
            res += dp.back()[i];
            res %= MODE;
        }
        return res;
    }
};