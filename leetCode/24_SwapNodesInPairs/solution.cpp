#include <iostream>
#include <vector>

/*
Given a linked list, swap every two adjacent nodes and return its head

warn : you man not modify the values in the list's nodes Only nodes itself may be changed

*/
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//  1 2 3 4
// 인접한 페어를 바꿔라 요렇게 2 1 4 3



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *temp; 
        ListNode *res;
        if(!head) return nullptr;
        if(!(head->next)) return head;
        temp = head->next->next; 
        head->next->next = head;
        res = head->next;
        head->next = swapPairs(temp);
        return res;
    }
};