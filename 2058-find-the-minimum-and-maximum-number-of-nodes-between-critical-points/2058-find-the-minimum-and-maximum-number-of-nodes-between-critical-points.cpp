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
        ListNode*temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        if(count<=2) return {-1,-1};
        ListNode*temp1 = head->next;
        ListNode*prev = head;
        int c = 0;
        vector<int> ans;
        while(temp1->next!=NULL){
            c++;
            if(prev->val>temp1->val && temp1->val<temp1->next->val){
                ans.push_back(c);
            }
            if(prev->val<temp1->val && temp1->val>temp1->next->val){
                ans.push_back(c);
            }
            prev = temp1;
            temp1= temp1->next;
        }
        int n = ans.size();
        if(n<2) return {-1,-1};
        int mdist = 1e9;
        for(int i = 0;i<n-1;i++){
            mdist = min(mdist,ans[i+1]-ans[i]);
        }
        int Mdist = ans[n-1]- ans[0];

        return {mdist,Mdist};
    }
};