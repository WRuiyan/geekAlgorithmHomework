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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post = postorder;
        in = inorder;
        return build(0, post.size(),0,in.size());
    }
private:
    vector<int> post;
    vector<int> in;
    // 区间左闭右开
    TreeNode* build(int pL, int pR, int iL, int iR){
        if (pL == pR) return nullptr;
        int rVal = post[pR -1];
        int pos;
        for ( pos = iL; pos < iR; pos++) 
            if(in[pos] == rVal) break;
        int lN = pos - iL;
        int rN = iR - pos;
        TreeNode* tem = new TreeNode(rVal);
        tem->left = build(pL ,pL + lN ,iL,pos);
        tem->right = build(pL + lN ,pR -1 ,pos + 1,iR);
        return tem;          
    }
};
