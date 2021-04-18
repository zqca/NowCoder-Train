#include <iostream>
#include <string>
#include <vector>

using namespace std;

string LCS(string str1, string str2) {
        // write code here
    int pos, maxLen = 0;
    int m = str1.length();
    int n = str2.length();

    vector<vector<int> >dp(m+1, vector<int>(n+1,0));//包含s[i] t[j]的子串的长度

    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    pos = j - 1;//记录在str2中的索引    
                }     
            }
        }
    }
    return str2.substr(pos - maxLen + 1, maxLen);
}

int main() {
    string s = "z194";
    string t = "dz1D94";
    cout << LCS(s, t) << endl;

    return 0;
}

