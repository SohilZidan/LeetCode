class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right_sum = -nums[0];
        for(int i: nums) right_sum += i;
        int left_sum = 0;
        size_t arr_idx = 0;
        while((right_sum != left_sum) && (++arr_idx) < nums.size())
        {
            right_sum -= nums[arr_idx];
            left_sum += nums[arr_idx-1];
        }
        if(arr_idx == nums.size()) return -1;
        return arr_idx;
    }
};