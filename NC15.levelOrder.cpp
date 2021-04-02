#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

vector<vector<int> > levelOrder(TreeNode* root) {
        // write code here
    vector<vector<int> > res;
    vector<int> tmp_vec;
    if(root == NULL) return res;

    queue<TreeNode*> que;//只会保存每一层的节点，不包含空节点
    que.push(root);
    TreeNode* tmp;

    while(que.size()){
        tmp_vec.clear();
        int n = que.size();
        for(int i = 0; i < n; ++i) {
            tmp = que.front();
            que.pop();
       
            tmp_vec.push_back(tmp->val);
            if(tmp->left) que.push(tmp->left);
            if(tmp->right) que.push(tmp->right);
        }
        res.push_back(tmp_vec);
        
    }

    return res;     
}

int main() {
    return 0;
}