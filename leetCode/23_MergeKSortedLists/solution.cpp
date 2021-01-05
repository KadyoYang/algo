#include <iostream>
#include <vector>

using namespace std;

/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []
*/

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* res = nullptr;
        for(int i = 0 ; i < k ; i++){
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        ListNode *result;
        ListNode **next;
        if(l1->val <= l2->val){
            next = &(l1->next);
            result = l1;
            l1 = l1->next;
        }else{
            next = &(l2->next);
            result = l2;
            l2 = l2->next;
        }

        while(l1 && l2){
            if(l1->val <= l2->val){ // 여기서 l2가 큰놈이니까 l2보다 작을시 계속 l1 앞으로 가면서 비교 해보자 비교가
                (*next) = l1;
                next = &((*next)->next);
                l1 = l1->next;
                while(l1 != nullptr && l1->val <= l2->val){ 
                    next = &((*next)->next);
                    l1 = l1->next;
                }
            }else{
                (*next) = l2;
                next = &((*next)->next);
                l2 = l2->next;
                while(l2 != nullptr && l1->val > l2->val){ 
                    next = &((*next)->next);
                    l2 = l2->next;
                }
            }
        }

        if(l1 == nullptr){
            (*next) = l2;
        }else{
            (*next) = l1;
        }    
        return result;
    }
};

class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main(){

    return 0;
}