设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
代码长度限制
16 KB
时间限制
200 ms
内存限制
64 MB

#include<stdio.h>
#include<stdlib.h>
typedef struct Node Seq;
typedef struct Node *SeqPoint;
struct Node{
    int data[2];
    SeqPoint next;
};

void Input(SeqPoint s);
void add(Seq a, Seq b, SeqPoint c);
void mul(Seq a, Seq b, SeqPoint c);
void mul1(int data[],SeqPoint tb,SeqPoint* result);
void OutPut(Seq s);

int main(){
    Seq a,b,c;
    a.next = NULL;
    b.next = NULL;
    c.next = NULL;
    Input(&a);
    Input(&b);
   
    mul(a,b,&c);
    OutPut(c);
    
    c.next = NULL;
    add(a,b,&c);
    OutPut(c);

    return 0;
}

void Input(SeqPoint s){
    SeqPoint temp,current;
    int n,f = 0;
    current = s;
    f = scanf("%d",&n);
    while(n > 0){
        temp = (SeqPoint)malloc(sizeof(Seq));
        f = scanf("%d %d",&temp->data[0],&temp->data[1]);
        temp->next = NULL;
        current->next = temp;
        current = current->next;
        n--;
    }
}

void add(Seq a, Seq b, SeqPoint c){
    SeqPoint temp, current, ta,tb;
    current = c;
    ta = a.next;
    tb = b.next;
    while(ta != NULL && tb != NULL){
        temp = (SeqPoint)malloc(sizeof(Seq));
        if(ta->data[1] < tb->data[1]) {temp->data[0] = tb->data[0]; temp->data[1] = tb->data[1]; tb = tb->next;}
        else if(ta->data[1] > tb->data[1]){temp->data[0] = ta->data[0]; temp->data[1] = ta->data[1]; ta = ta->next;}
        else{temp->data[0] = ta->data[0] + tb->data[0]; temp->data[1] = ta->data[1]; ta = ta->next; tb = tb->next;}
        if(temp->data[0] == 0){
            continue;
        }
        temp->next = NULL;
        current->next = temp;
        current = current->next;
    }
    while(ta!=NULL){
        temp = (SeqPoint)malloc(sizeof(Seq));
        temp->data[0] = ta->data[0];
        temp->data[1] = ta->data[1];
        temp->next = NULL;
        current->next = temp;
        current = current->next;
        ta = ta->next;
    }
    while(tb!=NULL){
        temp = (SeqPoint)malloc(sizeof(Seq));
        temp->data[0] = tb->data[0];
        temp->data[1] = tb->data[1];
        temp->next = NULL;
        current->next = temp;
        current = current->next;
        tb = tb->next; 
    }
}

void mul(Seq a, Seq b, SeqPoint c){
    SeqPoint ta, tb, temp;
    c->next = NULL;
    ta = a.next;
    tb = b.next;
    while(ta != NULL){
    	temp = (SeqPoint)malloc(sizeof(Seq));
        temp->next = NULL;
        mul1(ta->data,tb,&temp);
        add(*temp,*c,c);
        ta = ta->next;
    }
}

void mul1(int data[],SeqPoint tb,SeqPoint* result){
    SeqPoint current = *result;
    SeqPoint temp;
    while(tb != NULL){
		temp = (SeqPoint)malloc(sizeof(Seq));
		temp->next = NULL;
        temp->data[1] = tb->data[1] + data[1];
        temp->data[0] = tb->data[0] * data[0];
        tb = tb->next;
        current->next = temp;
        current = current->next;
    }   
}

void OutPut(Seq s){
	SeqPoint current = s.next;
    if(current == NULL){
        printf("0 0");
    }
    while(current != NULL){
        printf("%d %d",current->data[0],current->data[1]);  
        if(current->next != NULL){
            printf(" ");
        }
		current = current->next;
    }
    printf("\n");
}
