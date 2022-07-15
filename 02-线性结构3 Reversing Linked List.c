Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K=3, then you must output 3→2→1→6→5→4; if K=4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (≤10 
5
 ) which is the total number of nodes, and a positive K (≤N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

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
