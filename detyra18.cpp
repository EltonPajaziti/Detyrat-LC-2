#include <iostream>

using namespace std;

// Definition for a singly-linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr != NULL) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

void printList(ListNode* head) {
    ListNode* curr = head;

    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }

    cout << endl;
}

int main() {
    // Example 1: [1,2,3,4,5]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Original linked list (Example 1): ";
    printList(head1);

    ListNode* reversedHead1 = reverseList(head1);

    cout << "Reversed linked list (Example 1): ";
    printList(reversedHead1);

    // Example 2: [1,2]
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "Original linked list (Example 2): ";
    printList(head2);

    ListNode* reversedHead2 = reverseList(head2);

    cout << "Reversed linked list (Example 2): ";
    printList(reversedHead2);

    // Example 3: []
    ListNode* head3 = NULL;

    cout << "Original linked list (Example 3): ";
    printList(head3);

    ListNode* reversedHead3 = reverseList(head3);

    cout << "Reversed linked list (Example 3): ";
    printList(reversedHead3);

    return 0;
}
