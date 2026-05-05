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
        vector<int>ele;
        ListNode* temp = head;
        while(temp != NULL){
            ele.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int n = ele.size();
        if(n == 0) return NULL;
        k = k % n;
        int t = n-k;
        reverse(ele.begin(), ele.begin()+t);
        reverse(ele.begin()+t, ele.end());
        reverse(ele.begin(), ele.end());
        for(int i = 0; i < n; i++){
            temp->val = ele[i];
            temp = temp->next;
        }
        return head;
    }
};