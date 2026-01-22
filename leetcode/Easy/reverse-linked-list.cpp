class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* res = nullptr; 

        while (head) {
            ListNode* a = head;  
            head = head->next;  
            
            a->next = res;      
            res = a;           
        }

        return res; 
    }
};
