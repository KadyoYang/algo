/*
20. Valid Parentheses
Easy

Add to List

Share
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        
        if(s.size()%2 != 0){
            return false;
        }

        for(char ch: s){
            switch (ch){
                case ')':{
                    if(!temp.empty() && temp.top() == '('){
                        temp.pop();
                        break;
                    }else{
                        return false;
                    }
                }
                case ']':{
                    if(!temp.empty() && temp.top() == '['){
                        temp.pop();
                        break;
                    }else{
                        return false;
                    }

                }
                case '}':{
                    if(!temp.empty() && temp.top() == '{'){
                        temp.pop();
                        break;
                    }else{
                        return false;
                    }
                }
                default: {
                    temp.push(ch);
                    break;
                }
            }
        }


        if(temp.empty()) return true;
        else return false;

    }
};