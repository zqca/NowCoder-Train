#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxLength(vector<int>& arr) {
    int len = arr.size();
    if(len == 0) return 0;

    unordered_map<int,int> myMap;
    int ans = 1;//至少有一个元素

    for(int i = 0; i < len; ++i){
        if(i + 1 < len && arr[i] == arr[i+1]){
            continue;//去除重复，指向最后一个重复的元素
        }
        myMap.clear();//清空本轮计数器
        myMap[arr[i]] = i;

        for(int j = i + 1; j < len; ++j){
            if(myMap[arr[j]]){
                //已经出现过,1,1,2,3,2，开始结算
                ans = ans < j - i ? j - i : ans;
                i = myMap[arr[j]];//i指向第一次出现的位置，由于for的++i,下一轮会正常
                break;
            }
            myMap[arr[j]] = j;//记录第一次出现的索引

            if(j == len - 1){
                ans = ans < j - i + 1 ? j - i + 1 : ans;//结算
            }
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1,1,1,2,2,2,2,3,3,3,4};
    int ans = maxLength(arr);

    cout<<ans<<endl;

    return 0;
}