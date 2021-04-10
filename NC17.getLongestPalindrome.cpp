#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getLongestPalindrome(string A, int n) {

    vector<vector<int> > dp(n, vector<int>(n, 0));
    //dp[i][j]表示A[i:j]是否是回文,默认false
    int start, end, maxLen = 0;

    //需要从矩阵右下角开始，只保留左上角部分的三角区域,从右下角开始，按行遍历
    for(int i = n - 1; i >= 0; --i){
        for(int j = i; j < n; ++j){
            if(A[i] == A[j]){
                if(j - i < 2){
                    //区间只有一个元素，或者两个元素。前提是头尾相同
                    dp[i][j] = 1;
                }
                else {
                    //区间包含的元素超过2个
                    if(dp[i + 1][j - 1]){
                        //中间部分是回文的
                        dp[i][j] = 1;
                    }
                }
            }

            if(dp[i][j] && j - i + 1 > maxLen){
                //如果当前区间是回文的，记录最大长度以及开始结束位置
                start = i;
                end = j;
                maxLen = j - i + 1;
            }
        }
    }
    
    return maxLen; 
}

int main() {
    string A = "abc1234321ab";
    int n = A.length();

    cout << getLongestPalindrome(A, n) << endl;

    return 0;
}