#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0, right = n - 1, bottom = m - 1, left = 0;//最大边界
    vector<int> res;
    int count = 0;

    while(count <= m * n){
        for(int j = left; j <= right; j++) {
            res.push_back(matrix[top][j]);
            ++count;
        }

        if(count == m*n) break;

        for(int i = top + 1; i <= bottom; i++) {
            res.push_back(matrix[i][right]);
            ++count;
        }

        if(count == m*n) break;

        for(int j = right - 1; j >= left; j--) {
            res.push_back(matrix[bottom][j]);
            ++count;
        }

        if(count == m*n) break;

        for(int i = bottom - 1; i > top; i--) {
            res.push_back(matrix[i][left]);
            ++count;
        }

        left++;right--;
        top++;bottom--;

    }
    return res;

        
}

int main()
{
    vector<vector<int> > matrix = {{1,2,3},{8,9,4},{7,6,5}};
    vector<int> ans = spiralOrder(matrix);
    return 0;
}
