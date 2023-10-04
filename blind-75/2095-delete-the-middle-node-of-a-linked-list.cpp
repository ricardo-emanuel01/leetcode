using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode *deleteMiddle(ListNode *head) {
    ListNode *slow = head;
    ListNode *runner = head;
    ListNode *prev = NULL;

    while (runner != NULL && runner->next != NULL) {
        prev = slow;
        slow = slow->next;
        runner = runner->next->next;
    }

    if (prev == NULL) return NULL;
    prev->next = slow->next;
    delete slow;

    return head;
}
