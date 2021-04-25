#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > result;
    vector<int> tmp;
    int len = num.size();
    if(len < 3) return result;

    sort(num.begin(), num.end());
    int i, j, k;

    for(i = 0; i <= len - 3; ++i){
        if(num[i] > 0) break;//不存在解
        //跳过重复的i
        if(i >= 1 && num[i] == num[i - 1]){
            continue;
        }
        tmp.clear();
        tmp.push_back(num[i]);

        j = i + 1;
        k = len - 1;
        while(k > j){
        
            if(num[j] + num[k] == -num[i]){
                tmp.push_back(num[j]);
                tmp.push_back(num[k]);

                result.push_back(tmp);
                //本轮还有机会
                tmp.pop_back();
                tmp.pop_back();
                while(j < k && num[j] == num[j + 1]) ++j;//跳过重复的j
                while(k > j && num[k] == num[k - 1]) --k;//跳过重复的k
                ++j;
                --k;
                continue;
            }
            if(num[j] + num[k] > -num[i]){
                --k;
            }
            else{
                ++j;
            }
        }

    }
    return result;  
}


int main()
{
   vector<int> num = {-1,0,1,2,-1,-4};
   vector<vector<int> > ans = threeSum(num);

   return 0;
}
