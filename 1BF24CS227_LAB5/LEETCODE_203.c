/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy1;         
    struct ListNode *prev1 = &dummy1;
    dummy1.next = NULL;

    struct ListNode dummy2;         
    struct ListNode *prev2 = &dummy2;
    dummy2.next = NULL;

    struct ListNode *temp = head;

    while (temp != NULL) {

        if (temp->val == val) {
            prev1->next = temp;
            prev1 = temp;
        } else {
            prev2->next = temp;
            prev2 = temp;
        }

        temp = temp->next;
    }

    
    prev1->next = NULL;
    prev2->next = NULL;

    
    return dummy2.next;
}
