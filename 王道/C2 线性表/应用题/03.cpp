// 长度为 n 的顺寻表 L
// 时间 O(n) 空间 O (1)
// 删除所有值为 x 的数据元素

#include<iostream>
using namespace std;

#define MaxSize 50
#define ElemType int 

typedef struct 
{
    ElemType data[MaxSize];
    int length;
}SqList;

void delete_x(SqList &L,ElemType x){
    
