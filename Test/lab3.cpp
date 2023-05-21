// --------1 chu so it is OK--------------
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define MAX 200
//-----------------------------
struct Stack
{
    char DATA[MAX];
    int TOP;
};
struct Stack1
{
    int DATA[MAX];
    int TOP;
};
//-----------------------------
void init(Stack *S)
{
    S->TOP = -1;
}
int isEmpty(Stack *S)
{
    if (S->TOP == -1)
        return 1;

    return 0;
}
//----------------------------------
void Push(struct Stack *S, char item)
{
    if (S->TOP == (MAX - 1))
    {
        printf("\nStack is full");
    }
    else
    {
        ++S->TOP;
        S->DATA[S->TOP] = item;
    }
}
//----------------------------------
void Push1(struct Stack1 *S, int item)
{
    if (S->TOP == (MAX - 1))
    {
        printf("\nStack is full");
    }
    else
    {
        ++S->TOP;
        S->DATA[S->TOP] = item;
    }
}
//--------------------------
char top(Stack *S)
{
    return (S->DATA[S->TOP]);
}
//---------------------------------
char Pop(struct Stack *S)
{
    char ret = -1;
    if (S->TOP == -1)
        printf("\nStack is empty");
    else
    {
        ret = S->DATA[S->TOP];
        --S->TOP;
    }
    return ret;
} //-----------------------------------
int Precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x == '%')
        return 2;

    return 3;
}
//------------------------------------
void InfixtoPostfix(char infix[], char postfix[])
{
    Stack S;
    int x, token;
    int i = 0, j = 0; // i-index of infix,j-index of postfix
    init(&S);
    // S->TOP = -1;
    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (isalnum(token)) // token==1 khong phai toan tu, dau ngoac
            postfix[j++] = token;
        else if (token == '(')
            Push(&S, '(');
        else if (token == ')')
            while ((x = Pop(&S)) != '(')
                postfix[j++] = x;
        else
        {
            while (Precedence(token) <= Precedence(top(&S)) && !isEmpty(&S))
            {
                x = Pop(&S);
                postfix[j++] = x;
            }
            Push(&S, token);
        }
    }

    while (!isEmpty(&S))
    {
        x = Pop(&S);
        postfix[j++] = x;
    }

    postfix[j] = '\0';
}
//----------------------------
float Evaluate(char *Postfix)
{
    struct Stack S;
    char *p;
    float op1, op2, result;
    S.TOP = -1;
    p = &Postfix[0];
    while (*p != '\0')
    {
        while (*p == ' ' || *p == '\t')
        {
            p++;
        }
        if (isdigit(*p))
        {
            int num = 0;
            // while (isdigit(*p))
            //			{
            //				num = num*10 + *p - 48;
            //				*p++;
            //			}
            // cout<<"\n*p="<<*p;
            // num=*p;
            // cout<<"\nnum="<<num;
            Push(&S, *p);
        }
        else
        {
            op1 = Pop(&S); // cout<<"\nop1="<<op1-48;
            op2 = Pop(&S); // cout<<"\nop2="<<op2-48;
            switch (*p)
            {
            case '+':
                result = (op2 - 48) + (op1 - 48); // cout<<"\nresult +="<<result;
                break;
            case '-':
                result = (op2 - 48) - (op1 - 48); // cout<<"\nresult -="<<result;
                break;
            case '/':
                result = (op2 - 48) / (op1 - 48); // cout<<"\nresult /="<<result;
                break;
            case '*':
                result = (op2 - 48) * (op1 - 48); // cout<<"\nresult *="<<result;
                break;
            default:
                printf("\nInvalid Operator");
                return 0;
            }
            Push(&S, result + 48);
        }
        p++;
    }
    result = Pop(&S);
    return result - 48;
}
//----------------------------
int main()
{
    char A[MAX], B[MAX];
    printf("\n Bieu thuc can tinh: ");
    gets(A);
    InfixtoPostfix(A, B);
    printf("\n Bieu thuc hau to: %s", B);
    printf("\n Gia tri cua bieu thuc la: %.2f\n", Evaluate(&B[0]));
    gets(A);
    return 0;
}