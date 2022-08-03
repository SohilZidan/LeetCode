class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1,-1};
        if(nums.empty()) return res;

        int start = searchLeft(nums, target, 0, nums.size()-1);
        if(nums[start] != target) return res;
        res[0] = start;

        res[1] = searchRight(nums, target, start, nums.size()-1);
        return res;
    }

    int searchLeft(vector<int>& nums, int target, int start, int end){
        while(start<end)
        {
            int mid = start/2. + end/2.;
            cout << "Left mid: " << to_string(mid) << endl;
            if(nums[mid] >= target) end = mid;
            else start = mid + 1;
        }
        return start;
    }

    int searchRight(vector<int>& nums, int target, int start, int end){
        while(start<end)
        {
            int mid = start/2. + end/2. + 1;
            cout << "Right mid: " << to_string(mid) << endl;
            if(nums[mid] <= target) start = mid;
            else end = mid - 1;
        }
        return start;
    }
};