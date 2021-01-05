/* Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1] */

#include <iostream>
#include <vector>


using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};



class Solution1
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode** t1 = &head;
        ListNode* t2 = head;

        for(int i = 1; i < n; ++i)
        {
            t2 = t2->next;
        }
        while(t2->next != NULL)
        {
            t1 = &((*t1)->next);
            t2 = t2->next;
        }
        *t1 = (*t1)->next;
        
        return head;
    }
};

class Solution2{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        ListNode* second = dummy;

        // tempNode n번전진
        for(int i = 0; i < n && first->next != nullptr; i++){
            first = first->next;
        }
        
        while(first->next != nullptr){
            first = first->next;
            second = second->next;
        }
        // tempNode-> next == nullptr인 현상황
        // 작업 시작 후 리턴
        second->next = second->next->next;
        return dummy->next;
    }
};

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){

        ListNode* pFirst = head;
        ListNode** ppSecond = &head;

        // tempNode n번전진
        for(int i = 1; i < n && pFirst->next != nullptr; i++){
            pFirst = pFirst->next;
        }
        
        while(pFirst->next != nullptr){
            pFirst = pFirst->next;
            ppSecond = &(    (*ppSecond)->next   );
        }
        // tempNode-> next == nullptr인 현상황
        // ppSecond가 B의 next변수의 주소를 가지고 있는 상황에서 끝난다.
        
        // ABCD n=2
        // B의 next변수에 담겨져있는 놈 == 다음 c의 주소를 템프에 담군다
        ListNode *temp = *ppSecond;
        // ppSecond에는 B의 next 의 주소가 담겨져있다. B의 *next 는 C의 주소를 담고있다.
        *ppSecond = (*ppSecond)->next;
        delete temp;
        return head;
    }
};




// 정수형 그냥 뭐 받아노는거는 할수있는데
// 새로 만든 객체 포인터 받아올때는 투포인터써야겠다..
void swap1(int **a, int **b){
    int *temp = *a;
    *a = *b;
    *b = temp;
}
void swap(int** num1, int** num2)    //싱글 포인터의 주소 값을 더블 포인터 매개변수로 얻어옴
{
    int *tmp;        //임시로 사용할 싱글 포인터
    tmp = *num1;    
    *num1 = *num2;
    *num2 = tmp;
}
void ini(int *a, int* b){
    *a = 4;
    *b = 6;
}

int main(){
    int num1 = 2;
    int num2 = 3;
   /*  int* num1p = &num1;
    int* num2p = &num2;
    swap(&num1p, &num2p); 
    cout << *num1p << endl;
    변수명==주소
    주소는 밸류를 가지고있음
    int a = 4;
    0x00sdf0sdf 4

    */

   ini(&num1, &num2);
   cout << num1 << endl;
    
   
    return 0;
}