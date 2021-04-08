#include <iostream>

using namespace std;

//  leetcode 25
struct ListNode {
    int val;
    struct ListNode *next;
};

void reverse(ListNode* start, ListNode* end){
    //反转 (start,end)之间的元素
    ListNode* pre, *cur, *tmp;
    ListNode* left = start->next;

    pre = end;
    cur = left;
    while(cur != end){
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    start->next = pre;
}

ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode *cur, *start, *dumb, *tmp;
    dumb = new ListNode();
    dumb->next = head;

    cur = dumb;
    int flag = 0;
    start = cur;
    while(cur!= NULL){    
        for(int i = 0; i < k; ++i){  
            cur = cur->next;
            if(cur == NULL) {
                //不足一组,结束
                flag = 1;
                break;
            } 
        }
        if(flag == 0){
            tmp = start->next;//start->next是本组的开头，交换后，是本组的最后一个元素。
            reverse(start, cur->next);
            start = tmp;//指向上一组的结尾，为下一次反转做准备
            cur = tmp;//指向上一组的结尾
        }
    }

    return dumb->next;
}

int main(){
    int k = 2;
    ListNode* head;

    int len = 4;
    ListNode* tmp, *tail, *dumb;
    dumb = new ListNode();
    tail = dumb;

    for(int i = 0; i < len; ++i){
        tmp = new ListNode();
        tmp->val = i;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
    }

    head = dumb->next;

    ListNode* ans = reverseKGroup(head, k);

    while(ans){
        cout<< ans->val<< " ";
        ans = ans->next;
    }
    
    return 0;
}
