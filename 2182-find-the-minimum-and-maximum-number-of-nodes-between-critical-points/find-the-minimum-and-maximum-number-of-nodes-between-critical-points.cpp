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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int previous = -1;
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        while (curr->next != nullptr) {
            int nextValue = curr->next->val;

            bool isCritical =
                (curr->val > prev->val && curr->val > nextValue) ||
                (curr->val < prev->val && curr->val < nextValue);

            if (isCritical) {
                if (first == -1) {
                    first = index;
                }

                if (previous != -1) {
                    minDistance = min(minDistance, index - previous);
                }

                previous = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (minDistance == INT_MAX) {
            return {-1, -1};
        }

        int maxDistance = previous - first;

        return {minDistance, maxDistance};
    }
};