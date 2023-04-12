// 栈在括号匹配中的应用
#include <stdbool.h>

typedef struct
{
    char chars[50];
    int top; // 栈顶指针
} *SqStack;

// 初始化操作
void InitStack(SqStack s);

// 判空操作
bool IsEmpty(SqStack s);

// 入栈操作
void Push(SqStack s, char a);

// 出栈操作
bool Pop(SqStack s,char *a);

bool Bracket(char b[], int length)
{
    SqStack s;    // 定义栈
    InitStack(s); // 初始化栈
    int i = 0;
    for (i; i < length; i++)
    {
        char a = b[i];
        if (a == "(" || a == "{" || a == "[")
        {
            Push(s, a); // 入栈
        }
        if (a == ")" || a == "}" || a == "]")
        {
            if (IsEmpty(s))
            {
                return false; // 此时栈为空，a为单身括号
            }
            char temp;
            Pop(s,&temp); // 栈不为空，弹出栈顶元素进行匹配
            if (a == ")" && temp != "(")
            {
                return false;
            }
            if (a == "]" && temp != "[")
            {
                return false;
            }
            if (a == "}" && temp != "{")
                return false;
        }
    }
    return IsEmpty(s);
}
