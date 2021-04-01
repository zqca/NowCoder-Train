#include <iostream>
#include <vector>

using namespace std;

void Heap_small(vector<int>& vec, int start, int end) {
    //调整成为小根堆
    int dad = start;
    int son = dad * 2 + 1;
    while(son <= end) {
        if(son + 1 <= end && vec[son] > vec[son + 1]) {
            //选择较小的孩子,如果右孩子不越界的话
            son++;
        }
        if(vec[dad] < vec[son]) {
            return; //不需要调整
        }
        else{
            swap(vec[dad], vec[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> ans;
    int len = input.size();
    if(k > len) return ans;

    for(int i = len/2 - 1; i >= 0; --i) {
        Heap_small(input, i, len - 1);
    }
    for(int i = len - 1; i >= 0 && k; --i) {
        swap(input[0], input[i]);
        ans.push_back(input[i]);
        --k;
        //相当于删除堆顶元素,然后调整剩下的未排序元素
        Heap_small(input, 0, i - 1);
    }

    return ans;
        
        
}

int main() {
    vector<int> input = {4,5,1,6,2,7,3,8};
    int k = 8;
    vector<int> ans = GetLeastNumbers_Solution(input, k);

    return 0;

}