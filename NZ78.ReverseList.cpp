#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

ListNode* constructList(vector<int> vec) {
    int len = vec.size();

    ListNode *dump = new ListNode(0);
    ListNode *tmp,*tail;
    tail = dump;
    for(int i = 0; i < len; ++i) {
        tmp = new ListNode(vec[i]);
        tail->next = tmp;
        tail = tmp;
    }
    return dump->next;
}
void printList(ListNode* head) {
    if(head){
        cout << head->val;
        head = head->next;
    }
    while(head) {
        cout << "->" << head->val;
        head = head->next;
    }
    cout << endl;
}

ListNode* ReverseList(ListNode* pHead) {
    if(pHead == NULL|| pHead->next == NULL) return pHead;
    ListNode *pre, *cur, *nxt;
    pre = NULL;
    cur = pHead;
    nxt = cur->next;
    
    while(nxt) {
        cur->next = pre;
        pre = cur;
        cur = nxt;
        nxt = nxt->next;
    }
    cur->next = pre;
    return cur;
}

int main() {
    vector<int> vec = {1,2,3,4,5};
    ListNode *head = constructList(vec);
    printList(head);

    head = ReverseList(head);
    printList(head);
    return 0;
}