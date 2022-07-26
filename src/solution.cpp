#include"../inc/solution.hpp"


void Solution::flatten(TreeNode* root)
{
    static std::vector<TreeNode*> nodes;
    MakePreorderVec(root, nodes);
    auto it = nodes.begin();
    while(it != nodes.end()-1)
    {
        (*it)->left = nullptr;
        (*it)->right = *(it+1);
        ++it;
    }
    nodes.back()->left = nullptr; nodes.back()->right = nullptr; 
}

void Solution::MakePreorderVec(TreeNode* root, std::vector<TreeNode*>& nodes)
{
    if(!root){ return; }
    nodes.push_back(root);
    MakePreorderVec(root->left, nodes);
    MakePreorderVec(root->right, nodes);
}