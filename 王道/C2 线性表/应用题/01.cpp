//   删除顺序表中最小元素（唯一），并返回其值
//   空闲位置由最后一个元素填补
//   若顺序表为空，返回错误信息并退出
#include<iostream>
using namespace std;

#define MaxSize 50
#define ElemType int 



typedef struct 
{
    ElemType data[MaxSize];
    int length;
}SqList;


int DeleteMin(SqList &L)
{
    if(L.length == 0) {
        cout<<"SeqList is empty"<<endl;
        return -1; // 如何确认是否是错误信息？
    }
    int min = L.data[0];
    int min_index = 0;
    for(int i = 0;i<L.length;i++) {
        if(L.data[i] < min) {
            min = L.data[i];
            min_index = i;
        }
    }
    L.data[min_index] = L.data[L.length-1];
    return min; // 没有对 length 进行修改
}

// 明显 return 的是 true false

bool Del_Min(SqList &L,ElemType &value){
    // 删除顺序表 L 中最小值的元素节点，并通过引用类型参数 value 返回其值
    // 若删除成功 ，返回 true ，否则返回 false
    if(L.length == 0) {
        cout<<"SeqList is empty"<<endl;
        return false;
    }
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++)
    {
        if(L.data[i] < value)
            pos = i;
            value = L.data[i];
    }
    L.data[pos] = L.data[L.length-1];
    L.length --;
    return true;
    
}