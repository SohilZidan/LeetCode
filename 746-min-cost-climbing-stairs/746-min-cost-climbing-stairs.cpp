class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len+1, 0);
        size_t prelast = len-1;
        dp[prelast] = cost[prelast] + dp[prelast+1];
        for(int i = len - 2; i >= 0; i--)
        {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        // for(size_t i = 0; i <= len; i++)
        //     cout<<dp[i]<<endl;
        return min(dp[0], dp[1]);
    }
};