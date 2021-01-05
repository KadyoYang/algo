#include <iostream>
#include <vector>
#include <math.h>

/*
2. Add Two Numbers
Medium
Add to List
Share
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    // 와 클래스마냥 생성자 와 콜론초기화냐! 대단하다 닝겐
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next){}
   
};

 void print(ListNode* temp){
        while(temp != nullptr){
        std::cout<< temp->val << " ";
        temp = temp->next;
        }
        std::cout << std::endl;
        return;
}

void printAddress(ListNode* temp){
    std::cout<< "me:" << temp << " next:"<< temp->next <<endl;
}

// 다 더한 다음에 더할때 10넘는거 그거 리스트 하나 만들어서 한번 올려주는작업?
// 아니 쒸밥ㄹ 1자리부터 시작하는거였냐 ㅆ비
// new 가 아닌 할당은 스택에 올라간다
// 스택에 올라간거는 범위 밖으로가면 메모리 해제된다.
// 하지만 new를 써서 동적할당을 하면 힙에 할당을 받기때문에 delete전까지는 메모리에 유지된다.
class Solution{
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* result;
        ListNode** node = &result;
        int val = 0;

        while(l1 != nullptr || l2 != nullptr || val > 0){
            if(l1 != nullptr){
                val += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                 val += l2->val;
                 l2 = l2->next;
            }
            (*node) = new ListNode(val%10);
            val = val / 10;        
            node = &((*node)->next);
        }
        return result;
    }
};

class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        ListNode *l3=NULL;
        ListNode **node=&l3;
        while(l1!=NULL||l2!=NULL||sum>0)
        {
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            (*node)=new ListNode(sum%10);
            sum/=10;
            node=&((*node)->next);
        }        
        return l3;
    }
};


int main(){
/*
int a = 0;


int *ap = &a;
int **app = &ap;

cout << &a << endl;
cout << &ap << endl;
cout << &app << endl;

cout << ap << endl;
cout << *ap << endl;
cout << *app <<endl;
cout << **app << endl;


cout << &(ap) << endl;
cout << &(*ap) << endl;
cout << &(*app) << endl;
cout << &(**app) << endl;
*/

    ListNode a1(2);
    ListNode a2(4);
    ListNode a3(3);
    a1.next = &a2;
    a2.next = &a3;
    
    
    ListNode b1(5);
    ListNode b2(6);
    ListNode b3(4);
    b1.next = &b2;
    b2.next = &b3;
    
\
    std::cout<< "test"  <<std::endl;
    Solution sol;
    print(sol.addTwoNumbers(&a1, &b1));

    std::cout<<std::endl;

    return 0;
}