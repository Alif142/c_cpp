#include <iostream>
#include "stacktype.cpp"

using namespace std;

bool isOperator(char c)
{
    return c == '/' || c == '*' || c == '+' || c == '-';
}

int precedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix)
{
    StackType<char> stack;

    string postfix;

    for(int i = 0; i < infix.length(); i++)
    {
        // Case: 1
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix = postfix + infix[i];
        }

        // Case: 2
        else if (infix[i] == '(')
        {
            stack.Push(infix[i]);
        }

        // Case: 3
        else if (infix[i] == ')')
        {
            while(stack.Top()!='(' && !stack.IsEmpty())
            {
                postfix = postfix + " ";
                postfix = postfix + stack.Top();
                stack.Pop();
            }
            stack.Pop();
        }

        // Case: 4
        else if (isOperator(infix[i]))
        {
            if (isOperator(infix[i]) && isOperator(infix[i + 2]))
            {
                return postfix = "Invalid Expression";
            }

            postfix = postfix + " ";

            if (stack.IsEmpty())
            {
                stack.Push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(stack.Top()))
                {
                    stack.Push(infix[i]);
                }
                else
                {
                    while((!stack.IsEmpty()) && (precedence(infix[i]) <= precedence(stack.Top())))
                    {
                        postfix = postfix + stack.Top();
                        stack.Pop();
                        postfix = postfix + " ";
                    }
                    stack.Push(infix[i]);
                }
            }
        }
    }
    while(!stack.IsEmpty())
    {
        if (stack.Top() == '(')
        {
            return postfix = "Invalid Expression";
        }

        postfix = postfix + " ";
        postfix = postfix + stack.Top();

        stack.Pop();
    }
    return postfix;
}

void print(string infix, string postfix)
{
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
}

void cal(string postfix)
{
    StackType<double> stk;
    string num = "";
    double result;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            num = num + postfix[i];
        }
        else if (postfix[i] == ' ')
        {
            if (!num.empty())
            {
                stk.Push(stoi(num));
                num = "";
            }
        }
        else if (isOperator(postfix[i]))
        {
            double operand2 = stk.Top();
            stk.Pop();
            double operand1 = stk.Top();
            stk.Pop();

            switch(postfix[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                cout << "Error: Unknown operator" << endl;
                return;
            }
            stk.Push(result);
        }
    }
    result = stk.Top();
    cout << "Result: " << result << endl;
}

int main()
{
    string infix;
    string postfix;

    infix = "10 + 3 * 5 / (16 - 4)";
    postfix = infixToPostfix(infix);
    print(infix, postfix);
    cal(postfix);
    cout << endl;


    infix = "(5 + 3) * 12 / 3";
    postfix = infixToPostfix(infix);
    print(infix, postfix);
    cal(postfix);
    cout << endl;

    infix = "3 + 4 / (2 - 3) * / 5";
    postfix = infixToPostfix(infix);
    print(infix, postfix);
    cout << endl;

    infix = "7 / 5 + (4 - (2) * 3";
    postfix = infixToPostfix(infix);
    print(infix, postfix);
    cout << endl;

    return 0;
}
