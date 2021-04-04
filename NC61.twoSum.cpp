#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        //题目要求下标从1开始
    vector<int> ans;
    unordered_map<int,int> map;//<key,index>
    for(int i = 0; i < numbers.size(); ++i) {
        auto it = map.find(target - numbers[i]);
        if(it != map.end()){
            ans.push_back(it->second + 1);
            ans.push_back(i + 1);
            break;
        }
        else{
            map[numbers[i]] = i;
        }

    }
    return ans;


}

int main(){
    return 0;

}