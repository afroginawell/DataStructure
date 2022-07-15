#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100002
typedef struct Node SeqList;
struct Node{
    int next;
    int data;
    int front;
};

void Read();
void Deal();
void Print();
int Count();

int k,n,head;
SeqList list[MAXSIZE];

int main(){
    
    // 读取
    Read();
    // 处理
    Deal();
    // 输出
    Print();
  
    return 0;
}

void Read(){
    int i, inputAdd, inputData, inputNext;
    scanf("%d %d %d",&head,&n,&k);
    list[head].front = MAXSIZE-1;
    list[MAXSIZE-1].next = head;
    for(i = 0; i < n; i++){
        scanf("%d %d %d",&inputAdd,&inputData,&inputNext);
        list[inputAdd].data = inputData;
        list[inputAdd].next = inputNext;
        if(inputNext != -1){
            list[inputNext].front = inputAdd; 
        }
    }
    head = MAXSIZE-1;
}

void Deal(){
    int m = Count();
    if(m > n){
        return;
    }else{
        n = m;
    }
    if(k == 1 || n == 1 || n == 0){
        return;
    }
    int p,q,i,j,nextPoint;
    p = head; 
   	q = list[p].next;
    for(i = 0; i < n/k;i++){
    	q = list[q].next;
        for(j = 0; j < k-1;j++){ 
            nextPoint = list[q].next;
			list[list[q].front].next = nextPoint;
			list[nextPoint].front = list[q].front;
			list[list[p].next].front = q;
			list[q].next = list[p].next;
			list[q].front = p; 
			list[p].next = q;
            q = nextPoint;
        }
        p = list[q].front;
    }
}

void Print(){
    int tempHead = list[head].next;
    while(list[tempHead].next != -1){
        printf("%05d %d %05d\n",tempHead,list[tempHead].data,list[tempHead].next);
        tempHead = list[tempHead].next;
    }
    printf("%05d %d %d",tempHead,list[tempHead].data,list[tempHead].next);
}

int Count(){
    int tempHead = list[head].next;
    int m = 0;
    while(list[tempHead].next != -1){
        tempHead = list[tempHead].next;
        m++;
    }
    m++;
    return m; 
}
