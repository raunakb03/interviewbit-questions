#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode *root) {
  ListNode *temp = root;
  while (temp) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << "END OF PRINTING" << endl;
}

ListNode *reverseList(ListNode *root) {
  if (!root)
    return root;
  ListNode *prev = (NULL);
  ListNode *curr = root;
  while (curr) {
    ListNode *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }
  return prev;
}

ListNode *reverseBetween(ListNode *A, int B, int C) {
  if (!A)
    return A;
  ListNode *dummy = new ListNode(-1);
  dummy->next = A;
  ListNode *temp = A;
  ListNode *prev = dummy;
  int cnt = B - 1;
  while (cnt--) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  ListNode *nextemp = temp;
  int len = C - B;
  while (len--) {
    nextemp = nextemp->next;
  }
  ListNode *nextnode = nextemp->next;
  nextemp->next = NULL;
  auto reversedNode = reverseList(temp);
  prev->next = reversedNode;
  while (reversedNode->next)
    reversedNode = reversedNode->next;
  reversedNode->next = nextnode;
  return dummy->next;
}
