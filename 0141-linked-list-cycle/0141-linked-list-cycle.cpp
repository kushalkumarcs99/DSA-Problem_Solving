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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> nodeSeen;
        ListNode *current = head;
        while(current != nullptr)
        {
            if(nodeSeen.find(current) != nodeSeen.end())
            {
                return true;
            }
            nodeSeen.insert(current);
            current = current->next;
        }
        return false;
    }
};