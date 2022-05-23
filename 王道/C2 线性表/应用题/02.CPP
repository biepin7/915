//  将顺序表 L 的所有元素逆置 要求算法的空间复杂度为 O(1)
#include<iostream>
using namespace std;

#define MaxSize 50
#define ElemType int 

typedef struct 
{
    ElemType data[MaxSize];
    int length;
}SqList;

void reverse(SqList &L){
    ElemType temp;
    for(int i = 0;i<L.length/2;i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = temp;
    }
}

// ps 本质是双指针，但是无需定义两个指针，用 L.length-1-i 替代右指针