#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

void construct_tree(TreeNode* root, vector<int> input) {
    queue<TreeNode*> que;//存放即将构造的节点
    int len = input.size();
    int i;
    TreeNode* cur;
    TreeNode* lchild;
    TreeNode* rchild;

    if(input[0] == INT32_MAX) {
        return;
    }
    else {
        root->val = input[0];
    }

    que.push(root);

    for(i = 1; i < len; i++) {
        cur = que.front();
        //设置左节点
        if(i < len && input[i] != INT32_MAX) {//不是null
            lchild = new TreeNode();
            lchild->val = input[i];
            cur->left = lchild;
            que.push(lchild);   
        }

        i++; 
    //设置右节点
        if(i < len && input[i] != INT32_MAX) {//不是null
            rchild = new TreeNode();
            rchild->val = input[i];
            cur->right = rchild;
            que.push(rchild);  
        }
        que.pop();

    }
}

void travel_front(vector<int>& ans, TreeNode* root) {
    if(root == NULL) return;

    ans.push_back(root->val);
    travel_front(ans, root->left);
    travel_front(ans, root->right);
} 

void travel_mid(vector<int>& ans, TreeNode* root) {
    if(root == NULL) return;

    travel_mid(ans, root->left);
    ans.push_back(root->val);
    travel_mid(ans, root->right);
} 

void travel_back(vector<int>& ans, TreeNode* root) {
    if(root == NULL) return;

    travel_back(ans, root->left);
    travel_back(ans, root->right);
    ans.push_back(root->val);
} 

vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
    vector<vector<int> > res;
    vector<int> tmp1, tmp2, tmp3;
    travel_front(tmp1, root);
    travel_mid(tmp2, root);
    travel_back(tmp3, root);

    res.push_back(tmp1);
    res.push_back(tmp2);
    res.push_back(tmp3);

    return res;
}

int main() {
    //输入层次遍历的二叉树，打印先序 中序 后续遍历的结果
    vector<int> input = {1,2,3};//使用INT32MAX代表空
    TreeNode *root = new TreeNode();
    construct_tree(root, input);
    vector<vector<int> > ans = threeOrders(root);
//打印，就不写了
    return 0;

}