/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || !head->next) {
            return head;
        }
        ListNode *cur = head;
        ListNode *h = NULL;
        ListNode *pre = NULL;
        while (cur ) {
            if (!h) {
                h = cur->next;
            }
            if (cur->next) {
            ListNode *nextCur = cur->next->next;
            ListNode *nextt = cur->next;
            cur->next =NULL;
            nextt->next = cur;
            if (pre) {
                pre->next = nextt;
            }
            pre = cur;
            cur = nextCur;} else {
                pre->next = cur;
                cur=cur->next;
            }
        }
        return h;
    }
};