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

ListNode *reverseList(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode *first = NULL;
    ListNode *second = head;
    ListNode *third;

    while (second != NULL) {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    return first;
}
