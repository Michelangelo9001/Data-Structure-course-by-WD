#include<stdio.h>
#define MaxSize 10

typedef struct{
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L){
    for(int i=0;i<MaxSize;i++)
        L.data[i]=0;
    L.length=0;
}

bool ListInsert(SqList &L,int i,int e){
    if(i<1||i>L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for(int j=L.length;j>=i;j--)
        L.data[j]=L.data[j-1];
    L.data[i-1]=e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L,int i,int &e){
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    for(int j=i;j<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return 0;
}

int main(){
    SqList L;
    InitList(L);
    //对该顺序表赋值部分省略
    if(ListInsert(L, 3, 3))
        printf("已插入");
    else
        printf("不合法");
    int e=-1;
    if(ListDelete(L,3,e))
        printf("已删除第三个元素，删除元素值为 %d\n",e);
    else
        printf("不合法");
    return 0;
}
