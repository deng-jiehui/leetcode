#include <iostream>
#include <vector>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* rail = new ListNode(0);
        ListNode* head = rail;
        while(l1 !=nullptr && l2 != nullptr){
            ListNode* temp ;
            if(l1->val+l2->val+carry < 10){
                temp = new ListNode(l1->val+l2->val+carry);
                carry = 0;}
            else{
                temp = new ListNode((l1->val+l2->val+carry)%10);
                carry = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
            rail->next = temp;
            rail = rail->next;
        }
        if(l1 !=nullptr){
            while (l1 != nullptr){
                ListNode* temp;
                if(l1->val+carry < 10){
                    temp = new ListNode(l1->val+carry);
                      carry = 0;}
                else{
                      temp = new ListNode((l1->val+carry)%10);
                      carry = 1;}
                rail->next = temp;
                rail = rail->next;
                l1 = l1->next;
            }      
        }
        else if(l2 !=nullptr){
            while (l2 != nullptr){
                ListNode* temp;
                if(l2->val+carry < 10){
                    temp = new ListNode(l2->val+carry);
                      carry = 0;}
                else{
                      temp = new ListNode((l2->val+carry)%10);
                      carry = 1;}
                rail->next = temp;
                rail = rail->next;
                l2 = l2->next;
            }
        }
        if(carry == 1){
            ListNode* temp = new ListNode(1);
            rail->next = temp;
            rail = rail->next;
        }
        ListNode* result = head->next;
        delete head;
        return result;
    }
};
int main(){
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1,l2);
    while(result != nullptr){
        std::cout<<result->val<<" ";
        result = result->next;
    }
    return 0;
}