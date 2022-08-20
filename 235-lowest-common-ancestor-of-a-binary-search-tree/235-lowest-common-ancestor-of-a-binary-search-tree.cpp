/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* wanderer = root;

        while(wanderer)
        {
        //     if(p->val == wanderer->val || q->val == wanderer->val)
        //         break;
        //     else if((q->val > wanderer->val &&  p->val < wanderer->val) || (q->val < wanderer->val &&  p->val > wanderer->val))
        //         break;
            if(q->val > wanderer->val && p->val > wanderer->val)
                wanderer = wanderer->right;
            else if(q->val < wanderer->val && p->val < wanderer->val)
                wanderer = wanderer->left;
            else break;
        }
        return wanderer;
    }
};