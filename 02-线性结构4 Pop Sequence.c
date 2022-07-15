Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2
Sample Output:
YES
NO
NO
YES
NO

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
