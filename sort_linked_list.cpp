#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int num): val(num), next(NULL) {};
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return;
}

ListNode* merge2Lists(ListNode* L1, ListNode* L2) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;

    while (L1 && L2) {
        if (L1->val <= L2->val) {
            curr->next = L1;
            L1 = L1->next;
        } else {
            curr->next = L2;
            L2 = L2->next;
        }
        curr = curr->next;
    }
    if (L1) {
        curr->next = L1;
    } else if (L2) {
        curr->next = L2;
    }
    curr = dummy->next;
    delete dummy;

    return curr;
}

ListNode* sortList(ListNode* head) {
    // Return if no node or only one node
    if (!head || !head->next) {
        return head;
    }
    ListNode* fast = head->next;
    ListNode* slow = head;

    // Find the middle node
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // Cut this list to two parts
    fast = slow;
    slow = slow->next;
    fast->next = NULL;
    ListNode* L1 = sortList(head);
    ListNode* L2 = sortList(slow);

    return merge2Lists(L1, L2);
}

int main() {
    ListNode* n1 = new ListNode(5);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(6);
    ListNode* n5 = new ListNode(1);
    ListNode* n6 = new ListNode(9);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    ListNode* head = n1;

    cout << "Before sort: ";
    printList(head);
    cout << "After sort: ";
    head = sortList(head);
    printList(head);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}
