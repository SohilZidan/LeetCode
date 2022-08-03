/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return divideAndConstructBST(nums, 0, nums.size()-1);
    }
    
    TreeNode* divideAndConstructBST(vector<int>& nums, int start, int end){
        if(end < start) return nullptr;
        if(start == end) return new TreeNode(nums[start]);
        int mid = end/2. + start/2.;
        auto left = divideAndConstructBST(nums, start, mid-1);
        auto right = divideAndConstructBST(nums, mid+1, end);
        return new TreeNode(nums[mid], left, right);
    }
};