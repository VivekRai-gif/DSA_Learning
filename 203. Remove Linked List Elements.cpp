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
    ListNode* removeElements(ListNode* head, int val) {

        vector<int> ans;

        ListNode* curr = head;

        while (curr) {
            if (curr->val != val)
                ans.push_back(curr->val);

            curr = curr->next;
        }

        if (ans.empty())
            return nullptr;

        ListNode* newHead = new ListNode(ans[0]);
        ListNode* temp = newHead;

        for (int i = 1; i < ans.size(); i++) {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }

        return newHead;
    }
};
