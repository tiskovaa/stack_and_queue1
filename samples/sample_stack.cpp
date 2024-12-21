#include "stack_and_queue.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

char invertBrackets(char ch)
{
    if (ch == '(') return ')';
    else if (ch == '[') return ']';
    else if (ch == '{') return '}';
    return ' ';
}

bool checkBrackets(string& s)
{
    mStack<char> stack;
    size_t len = s.length();
    for (size_t i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack.push(s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            if (!stack.isEmpty() && s[i] == invertBrackets(stack.top()))
                stack.pop();
            else return 0;
    }
    if (stack.isEmpty())
        return 1;
    else return 0;
}

int main()
{
    string str;
    cout << "Press 'x + enter' to exit" << std::endl;
    do
    {
        cin >> str;
        cout << checkBrackets(str) << std::endl;
    } while (str != "x");
}