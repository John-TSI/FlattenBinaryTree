#include"../inc/solution.hpp"


void Solution::flatten(TreeNode* root)
{
    static std::vector<TreeNode*> nodes;
    MakePreorderVec(root, nodes);
    auto it = nodes.begin();
    while(it != nodes.end())
    {
        (*it)->left = nullptr;
        (*it)->right = (it+1 == nodes.end()) ? nullptr : *(it+1);
        ++it;
    }
}

void Solution::MakePreorderVec(TreeNode* root, std::vector<TreeNode*>& nodes)
{
    if(!root){ return; }
    nodes.push_back(root);
    MakePreorderVec(root->left, nodes);
    MakePreorderVec(root->right, nodes);
}