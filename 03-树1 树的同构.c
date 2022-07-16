#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 12

typedef struct Node SeqList;
struct Node{
    int data;
    int left;
    int right;
};

SeqList* Read(int *len,int *cnt);
void Change(char c, int *a);
void Print(int *result,int cnt);
int* FindLeaves(SeqList* seq,int len,int cnt);
SeqList FindHead(SeqList *seq,int len);

int main(){
    
    int len,cnt;
    // 读取
    SeqList *seq = Read(&len,&cnt);
    
    // 查找
    int *result = FindLeaves(seq,len,cnt);
    
    // 输出
    Print(result,cnt);
    
    return 0;
}

SeqList* Read(int *len,int *cnt){
    int i;
    char c1,c2;
    SeqList *seq;
    
    *cnt = 0;
    scanf("%d",len);
    seq = (SeqList *)malloc((*len+1)*sizeof(SeqList));
    seq[0].right = 0; seq[0].left = 0; seq[0].data = 0;
    for(i = 1; i <= *len; i++){
    	scanf("%c",&c1);	// 读换行符 
        scanf("%c %c",&c1,&c2);
        Change(c1,&seq[i].left);
        Change(c2,&seq[i].right);
        seq[i].data = i;
        if(seq[i].left == 0 && seq[i].right == 0){
            *cnt = *cnt + 1;
        }
    }
    return seq;
}

void Change(char c, int *a){
    if(c == '-'){
        *a = 0;
    }else{
        *a = c - 48 + 1;
    }
}

void Print(int *result,int cnt){
    int i;
    for(i = 0; i < cnt; i++){
        printf("%d",result[i]);
        if(i != cnt - 1){
            printf(" ");
        }
    }
}

int* FindLeaves(SeqList* seq,int len,int cnt){
    int front,rear, j;
    int *result;
    SeqList head, current;
    SeqList *queue;
    
    result = (int *)malloc(cnt * sizeof(int));
    queue = (SeqList *)malloc(len*sizeof(SeqList));
    front = -1; rear = -1;
    
    head = FindHead(seq,len);
    printf("%d\n",head.data); 
    if(head.data == 0){
        return result;
    }
    
    queue[++rear] = head;
    j = 0;
    while(front != rear){
        current = queue[++front];
        if(current.left == 0 && current.right == 0){
            result[j] = current.data - 1;
            j++;
        }
        if(current.left != 0){
            queue[++rear] = seq[current.left];
        }
        if(current.right != 0){
            queue[++rear] = seq[current.right];
        }
    }
    return result;
}

SeqList FindHead(SeqList *seq,int len){
    int i, top, rear, front;
    SeqList *queue;
    SeqList current;
    
    queue = (SeqList *)malloc((len+1)*sizeof(SeqList));

    for(i = 1; i <= len;i++){
        rear = 0; front = 0;
        queue[++rear] = seq[i];
        while(rear != front){
            current = queue[++front];
            if(current.left != 0){
                queue[++rear] = seq[current.left];
            }
            if(current.right != 0){
                queue[++rear] = seq[current.right];
            }
        }
        if(rear == len){
            return seq[i];
        }
    }
    return seq[0];
}
