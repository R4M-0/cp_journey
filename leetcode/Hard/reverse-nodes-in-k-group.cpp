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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (!head || k == 1) return head;

            ListNode dummy(0);
            dummy.next = head;
            ListNode* prevGroupEnd = &dummy;

            while (true) {
                ListNode* kth = getKthNode(prevGroupEnd, k);
                if (!kth) break; // fewer than k nodes remain

                ListNode* groupStart = prevGroupEnd->next;
                ListNode* nextGroupStart = kth->next;

                // Reverse this group
                ListNode* prev = nextGroupStart;
                ListNode* curr = groupStart;

                while (curr != nextGroupStart) {
                    ListNode* temp = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = temp;
                }

                prevGroupEnd->next = kth;
                prevGroupEnd = groupStart; 
            }

            return dummy.next;
        }

    private:
        
        ListNode* getKthNode(ListNode* start, int k) {
            while (start && k > 0) {
                start = start->next;
                k--;
            }
            return start;
        }
};

