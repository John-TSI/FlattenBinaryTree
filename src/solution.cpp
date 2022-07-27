#include"../inc/solution.hpp"


void Solution::flatten(TreeNode* root)
{
    // --- first solution ---
/*     
    static std::vector<TreeNode*> nodes;
    MakePreorderVec(root, nodes);
    auto it = nodes.begin();
    while(it != nodes.end())
    {
        (*it)->left = nullptr;
        (*it)->right = (it+1 == nodes.end()) ? nullptr : *(it+1);
        ++it;
    }
 */

    // --- second solution ---
    RecursiveFlatten(root);
}


// --- first solution, requires O(# nodes) additional space and a call stack ---
void Solution::MakePreorderVec(TreeNode* root, std::vector<TreeNode*>& nodes)
{
    if(!root){ return; }
    nodes.push_back(root);
    MakePreorderVec(root->left, nodes);
    MakePreorderVec(root->right, nodes);
}


// --- second solution, requires a call stack ---
TreeNode* Solution::RecursiveFlatten(TreeNode* root)
{
    if(!root){ return nullptr; }
    TreeNode* leftTail = RecursiveFlatten(root->left);  // preorder traversal recursively visits left subtree before right subtree 
    TreeNode* rightTail = RecursiveFlatten(root->right);
    if(leftTail)  // if left subtree of current node exists
    {
        leftTail->right = root->right;  // connect tail of flattened left subtree to head of flattened right subtree
        root->right = root->left;  // insert flattened left subtree between root and right subtree
        root->left = nullptr;  // disconnect root from its left subtree as required
    }
    // returned TreeNode* depends on existence of subtrees
    if(rightTail || leftTail){ return rightTail ? rightTail : leftTail; }
    return root;
}