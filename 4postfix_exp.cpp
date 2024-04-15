// 4. Evaluate Postfix Expression using Stack ADT.

#include <iostream>
#include <stack>
using namespace std;

int evaluate(const string& postfix) 
{
    stack<int> s;

    for (char c : postfix) 
    {
        if (isdigit(c)) 
        {
            s.push(c - '0');
        }
        else 
        {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            
            switch(c) 
            {
                case '+': s.push(operand1 + operand2); 
                break;
                case '-': s.push(operand1 - operand2); 
                break;
                case '*': s.push(operand1 * operand2); 
                break;
                case '/': s.push(operand1 / operand2); 
                break;
            }
        }
    }

    return s.top();
}

int main() 
{
    string postfixexp;
    
    cout << "enter postfix expression: ";
    getline(cin, postfixexp);
    
    cout << "result: " << evaluate(postfixexp) << endl;
    
    return 0;
}
