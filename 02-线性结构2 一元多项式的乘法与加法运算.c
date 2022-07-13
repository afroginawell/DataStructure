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
