// 王道的顺序栈实现 top 指向 -1 

#include<iostream>
using namespace std;

#define MaxSize 3
#define ElemType int 


typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S)
{// 初始化栈顶指针
    S.top = -1;
}

bool StackEmpty(SqStack S)
{// 判断栈是否为空
    if(S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S,ElemType e)
{// 入栈
    if(S.top == MaxSize - 1) // 栈满
        return false;
    else
    {
        // S.top++;
        S.data[++S.top] = e;
        return true;
    }
}

bool Pop(SqStack &S,ElemType &e)
{// 出栈
    if(S.top == -1) // 栈空
        return false;
    else
    {
        e = S.data[S.top--];
        return true;
    }
}

bool GetTop(SqStack S,ElemType &e)
{// 获取栈顶元素
    if(S.top == -1) // 栈空
        return false;
    else
    {
        e = S.data[S.top];
        return true;
    }
}

void PrintStack(SqStack S)
{// 打印栈
    if(S.top == -1) // 栈空
        cout << "栈空" << endl;
    else
    {
        for(int i = 0;i <= S.top;i++)
            cout << S.data[i] << " ";
        cout << endl;
    }
}

int main(){
    SqStack s;
    InitStack(s);

    Push(s,1);
    PrintStack(s);
    
    Push(s,2);
    PrintStack(s);

    Push(s,3);
    PrintStack(s);
    
    cout << Push(s,4)<< endl;
    PrintStack(s);

    int x = -1;
    GetTop(s,x);
    cout<< x << endl;

    Pop(s,x);
    cout << x << endl;

    PrintStack(s);
    Pop(s,x);
    Pop(s,x);
    cout<<Pop(s,x)<<endl;
}