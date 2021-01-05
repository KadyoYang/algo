#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {  
        ListNode *answer = l1;
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }

        if(l1->val > l2->val){
            answer = l2;
            l2 = l1;
            l1 = answer;

        }
        
        ListNode *l1Start = l1;
        ListNode *l1End = l1->next;

        ListNode *l2Start = l2;
        ListNode *l2NewStartTemp = l2;

        while(l1Start != nullptr){
            if(l1End == nullptr){
                l1Start->next = l2Start;
                break;
            }
            if(l1End->val >= l2Start->val){
                l1Start->next = l2Start;
                while(l2Start->next != nullptr && l2Start->next->val <= l1End->val){
                    l2Start = l2Start->next;
                }
                l2NewStartTemp = l2Start->next;
                l2Start->next = l1End;
                l2Start = l2NewStartTemp;
            }
            
            l1Start = l1End;
             if(l1Start == nullptr || l2Start == nullptr) break;
            l1End = l1Start->next;
 
        }

        return answer;
    }
};

class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {  
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }


        while(true){
            if(l1 == nullptr){
                dummy->next = l2;
                break;
            }else if(l2 == nullptr){
                dummy->next = l1;
                break;
            }else if(l1->val < l2->val){
                dummy->next = l1;
                l1 = l1->next;
            }else{
                dummy->next = l2;
                l2 = l2->next;
            }
            dummy = dummy->next;
        }
        dummy = temp->next;
        delete temp;
        return dummy;
    }
};

class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {  
        ListNode *dummy = new ListNode(0);
        ListNode *temp;

        
        ListNode **nextpp = &(dummy->next);

        while(l1 != nullptr && l2 != nullptr){

            if(l1->val <= l2->val){
                (*nextpp) = l1;
                l1 = l1->next;
                nextpp = &((*nextpp)->next);
            }else{
                (*nextpp) = l2;
                l2 = l2->next;
                nextpp = &((*nextpp)->next);
            }
        }

        if(l1 == nullptr){
                (*nextpp) = l2;   
            }
        else{
                (*nextpp) = l1;     
        }


        temp = dummy->next;
        delete dummy;
        return temp;
    }
};

class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {  
        ListNode *temp;

        if(l1 == nullptr){
                return l2;
        }
        if(l2 == nullptr){
                return l1;    
        }

        ListNode **nextpp;

        if(l1->val <= l2->val){
            temp = l1;
            nextpp = &(l1->next);
            l1 = l1->next;
        }else{
            temp = l2;
            nextpp = &(l2->next);
            l2 = l2->next;
        }

        

        while(l1 != nullptr && l2 != nullptr){
            
            if(l1->val <= l2->val){
                
                (*nextpp) = l1;
                l1 = l1->next;
                nextpp = &((*nextpp)->next);
            }else{
                cout << l1->val <<endl;
                (*nextpp) = l2;
                l2 = l2->next;
                nextpp = &((*nextpp)->next);
            }
        }

        if(l1 == nullptr){
                (*nextpp) = l2;   
            }
        else{
                (*nextpp) = l1;     
        }

        return temp;
    }
};

int main(){

    ListNode n3(4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);

    ListNode x3(4);
    ListNode x2(3, &x3);
    ListNode x1(1, &x2);
    
    Solution3 sol;
    sol.mergeTwoLists(&n1, &x1);

    return 0;
}
