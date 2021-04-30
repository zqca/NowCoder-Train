#include <iostream>
#include <vector>

using namespace std;
//O(n2),超时
vector<int> LIS(vector<int>& arr) {
        // write code here
    int len = arr.size();
    if(len < 2) return arr;

    vector<int> dp(len, 1);//以xx结尾的最长递增序列的长度
    vector<vector<int> > res(len, vector<int>());
    res[0].push_back(arr[0]);

    int maxlen, prepos, finalpos = 0;
    vector<int> pos;
    bool hasfound = false;

    for(int i = 1; i < len; i++){
        //第一次，记录所有小于当前值的索引，<pos,len>记录长度最大值maxlen
        //第二次，找到 len = maxlen的值
        //第三次，找到数字最小的
        pos.clear();
        maxlen = 1;
        hasfound = false;
        for(int j = 0; j < i; ++j){
            if(arr[j] < arr[i]){
                hasfound = true;
                maxlen = max(maxlen, dp[j]);
            }
        }

        if(hasfound){
            dp[i] = maxlen + 1;

            for(int j = 0; j < i; ++j){
                if(dp[j] == maxlen){
                    pos.push_back(j);
                }
            }

            prepos = pos[0];

            for(int k = 0; k < pos.size(); ++k){
                if(arr[prepos] > arr[pos[k]]){
                    prepos = pos[k];
                }
            }

            res[i] = res[prepos];
            res[i].push_back(arr[i]);

        }
        else{
            res[i].push_back(arr[i]);
        }
    }
    //找当前dp最大值;
    maxlen = 1;
    for(int i = 0; i < len; ++i){
        if(dp[i] > maxlen){
            maxlen = dp[i];
        }
    }
    pos.clear();
    for(int i = 0; i < len; ++i){
        if(dp[i] == maxlen){
            pos.push_back(i);
        }
    }
    finalpos = pos[0];
    for(int k = 0; k < pos.size(); ++k){
        if(arr[finalpos] > arr[pos[k]]){
            finalpos = pos[k];
        }
    }

    return res[finalpos];

}

int main()
{
   vector<int> arr = {1,2,8,6,4};
   vector<int> ans = LIS(arr);

   return 0;
}
