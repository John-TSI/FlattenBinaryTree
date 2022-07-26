#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include<vector>
#include"node.hpp"


class Solution
{
    public:
        void flatten(TreeNode*);
        void MakePreorderVec(TreeNode*, std::vector<TreeNode*>&);
};


#endif // SOLUTION_HPP