#include"../inc/solution.hpp"


void Solution::flatten(TreeNode* root)
{
    // --- first solution, requires O(# nodes) additional space and a call stack ---
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


    // --- second solution, requires a call stack  ---
/*     
    RecursiveFlatten(root);
 */


    // --- third solution, constant space complexity ---
    TreeNode* curr{root};
    while(curr)  // terminate once previous loop iteration sets curr->right = nullptr (curr is then tail of the constructed linked list)
    {
        if(curr->left)  // if current node has a left subtree
        {
            TreeNode* temp{curr->left};  // create pointer to root of curr's left subtree
            while(temp->right){ temp = temp->right; }  // traverse temp's right subtree to reach the inorder predecessor of curr
            temp->right = curr->right;  // link temp to the root of curr's right subtree
            curr->right = curr->left;  // link curr->right to root of its left subtree
        }
        curr = curr->right;  // follow the new right link of curr to reach the next curr node
    }
}


// --- first solution helper ---
void Solution::MakePreorderVec(TreeNode* root, std::vector<TreeNode*>& nodes)
{
    if(!root){ return; }
    nodes.push_back(root);
    MakePreorderVec(root->left, nodes);
    MakePreorderVec(root->right, nodes);
}


// --- second solution helper ---
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