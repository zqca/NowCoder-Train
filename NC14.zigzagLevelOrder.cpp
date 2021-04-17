#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    // write code here
    vector<vector<int> > ans;
    vector<int> vec;
    bool flag = true;//true为正序
    queue<TreeNode*> que;
    if(root == nullptr){
        return ans;
    }
    que.push(root);

    int level;
    TreeNode* node;
    while(!que.empty()){
        level = que.size();
        vec.clear();
        for(int i = 0; i < level; ++i){
            node = que.front();
            que.pop();
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
            vec.push_back(node->val);  
        }
        if(flag){
            //正序
            ans.push_back(vec);
            flag = false;
        }
        else{
            //逆序
            reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            flag = true;
        }

    }
    return ans;

}