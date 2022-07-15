#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 1001

typedef struct stack{
    int top;
    int data[MAXSIZE];
}SeqStack;

SeqStack s;
int m,n;
int Seq[MAXSIZE];

void Init();
void Read();
int Deal();

int main(){
    
    int count;
    scanf("%d %d %d",&m,&n,&count);
    while(count > 0){
        Init();
        Read();
        int flag = Deal();
        if(flag == 1){
            printf("YES");
        }else{
            printf("NO");
        }
        if(count != 1){
            printf("\n");
        }
        count--;
    }
    
    return 0;
}

void Init(){
    s.top = 0;
    s.data[s.top] = MAXSIZE;
}

void Read(){
    int i;
    for(i = 0; i < n;i++){
        scanf("%d",&Seq[i]);
    }
}

int Deal(){
    int i,j = 0;
    for(i = 1; i <= n; i++){
        // 先给堆栈进入一个元素
        s.data[++s.top] = i;
        if(s.top > m || s.top < 0){
            return 0;   // 如果已经超过容量了，就退出
        }
        if(s.top == m){ // 如果堆栈满了，就必须出栈
            if(s.data[s.top] != Seq[j]){
                return 0;
            }else{
                s.top--;
                j++;
            }
        }
        while(s.data[s.top] == Seq[j]){ // 堆栈有位置，就先判断栈顶元素是否可以出栈
            s.top--;
            j++;
        }
    }
    if(s.top == 0 && j == n){   //堆栈空了，并且序列也走完了
        return 1;
    }else{
        return 0;
    }
}
