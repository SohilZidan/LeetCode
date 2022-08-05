class Solution {
public:
    vector<int> dp;
    int len = 0;
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<int>(target+1, -1);
        dp[0] = 1;
        len = nums.size();
        return combinationSum(nums, target);
    }
    int combinationSum(vector<int>& nums, int target) {
        if(dp[target] != -1) return dp[target];
        
        int res = 0;
        for(size_t i = 0; i < len; i++)
        {
            if(target >= nums[i])
                res += combinationSum(nums, target - nums[i]);
        }
        dp[target] = res;
        return res;
    }
    
    
//     Time Limit Exceed
//     int combinationSum4(vector<int>& nums, int target) {
//         if(target == 0) return 1;
        
//         int res=0;
//         int len = nums.size();
//         for(size_t i = 0; i < len; i++)
//         {
//             if(target >= nums[i])
//                 res += combinationSum4(nums, target - nums[i]);
//         }
//         return res;
//     }
};