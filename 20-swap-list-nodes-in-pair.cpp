#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// swap every adjacent pair of nodes and return the head
ListNode *swapPairs(ListNode *head) {
    if(!head) return head; 
    ListNode* temp= head;
    ListNode* dummy = new ListNode(-1);
    dummy->next= head;
    ListNode* prev= dummy;
    while(temp && temp->next){
        ListNode* nxtt= temp->next->next;
        prev->next= temp->next;
        temp->next->next= temp;
        temp->next= nxtt;
        temp= nxtt;
        prev= prev->next->next;
    }
    return dummy->next;
}
