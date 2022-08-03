class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        //vector<int> res(nums.size());
        //res.at(0) = nums.at(0);
        for(size_t i = 1; i < nums.size(); i++)
        {
                nums.at(i) = nums.at(i-1) + nums.at(i);
        }
        return nums;
    }
};