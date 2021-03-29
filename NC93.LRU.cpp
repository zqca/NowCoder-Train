#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int key;
    int value;
    ListNode(int key, int value): key(key), value(value){}
};

int findpos(vector<ListNode> tmp, int key) {
    for(int i = 0; i < tmp.size(); ++i) {
        if(tmp[i].key == key) {
            return i;
        }
    }
    return -1;//不存在
}

vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> ans; 
        vector<ListNode> tmp;
        int pos;
        ListNode *node;//创建一个新节点

        for(int i = 0; i < operators.size(); ++i) {//1是set,2是get
            if(operators[i][0] == 2) {
                //get
                pos = findpos(tmp, operators[i][1]);
                if(pos == -1) {
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(tmp[pos].value);
                    tmp.insert(tmp.begin(), tmp[pos]);
                    tmp.erase(tmp.begin() + pos + 1);
                }
            }
            else {
                //set
                pos = findpos(tmp, operators[i][1]);

                //出现过
                if(pos != -1) {
                    tmp[pos].value = operators[i][2];
                    tmp.insert(tmp.begin(), tmp[pos]);
                    tmp.erase(tmp.begin() + pos + 1);
                }
                //没出现过
                else {
                    //直接插入在最前面,后面考虑要不要删除
                    node = new ListNode(operators[i][1], operators[i][2]);
                    tmp.insert(tmp.begin(), *node);

                    if(tmp.size() - 1 >= k) {
                        //删除最后一个
                        tmp.pop_back();
                    }        
                }   
            }

        }
        return ans;

}

int main() {
    vector<vector<int> > operators = {{1,1,1},{1,2,2},{1,3,2},{2,1},{1,4,4},{2,2}};
    int k = 3;
    vector<int> ans = LRU(operators, k);
    //输出ans
    return 0;
}