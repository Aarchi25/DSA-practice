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
class Solution {
public:
    ListNode* reverse(ListNode* head) {
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

    ListNode* removeNodes(ListNode* head) {

        // Step 1: Reverse the list
        head = reverse(head);

        // Step 2: Remove nodes smaller than maximum
        int maxi = head->val;
        ListNode* curr = head;

        while (curr->next != NULL) {

            if (curr->next->val < maxi) {
                curr->next = curr->next->next;
            }
            else {
                maxi = curr->next->val;
                curr = curr->next;
            }
        }

        // Step 3: Reverse again
        head = reverse(head);

        return head;
    }
};