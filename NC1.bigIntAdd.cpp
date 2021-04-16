#include <iostream>
#include <string>

using namespace std;

string solve(string s, string t) {
        // write code here
    string ans = "";
    int curry = 0;
    int tmp1, tmp2, tmp;
    int len1, len2;
    while(s.length() || t.length() || curry){
        //停止做加法的条件：两个数都没了，进位也没了
        len1 = s.length();
        len2 = t.length();
        if(len1 == 0){
            tmp1 = 0;
        }
        else{
            tmp1 = s[len1-1] - '0';
            s = s.substr(0,len1-1);
        }
        if(len2 == 0){
            tmp2 = 0;
        }
        else{
            tmp2 = t[len2-1] - '0';
            t = t.substr(0,len2-1);
        }

        tmp = (tmp1 + tmp2 + curry)%10;
        curry = (tmp1 + tmp2 + curry) >= 10 ? 1:0;
        ans = to_string(tmp) + ans;
    }
    return ans;
}

int main() {
    string s = "123";
    string t = "456";
    cout << solve(s, t);

    return 0;
}