#include <iostream>

using namespace std;

// Definition for a singly-linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

int getDecimalValue(ListNode* head) {
    int decimalValue = 0;

    while (head != NULL) {
        decimalValue = (decimalValue << 1) + head->val;
        head = head->next;
    }

    return decimalValue;
}

int main() {
    // Example 1: [1,0,1]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(0);
    head1->next->next = new ListNode(1);

    cout << "Decimal value of the linked list (Example 1): " << getDecimalValue(head1) << endl;

    // Example 2: [0]
    ListNode* head2 = new ListNode(0);

    cout << "Decimal value of the linked list (Example 2): " << getDecimalValue(head2) << endl;

    return 0;
}
//Time:O(n)
//Space:O(1)