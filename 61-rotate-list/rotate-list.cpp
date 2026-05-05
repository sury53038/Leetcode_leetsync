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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        if(temp == NULL) return NULL;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        count++;
        k = k % count;
        temp->next = head;
        temp = head;
        int n = count - k;
        for(int i = 0; i < n-1; i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};