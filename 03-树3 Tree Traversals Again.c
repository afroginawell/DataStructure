#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 31

typedef struct Node *TreeNode;
typedef struct Node{
    int data;
    TreeNode right;
    TreeNode left;
    int flag;
}TNode;

typedef struct Stack{
    TreeNode data[MAXSIZE];
    int top;
}TreeStack;

TreeNode Read(int *n);
int *Postorder(TreeNode head,int n);
void Print(int *reuslt, int n);
void PrintTree(TreeNode tree,int n);

int main(){
    
    int n;
    TreeNode head = Read(&n);
    
 //   PrintTree(head,n);
    int *data = Postorder(head,n);
    
    Print(data,n);
    
    return 0;
}

TreeNode Read(int *n){
    int data, i;
    char str[10];
    TreeNode head,current,temp;
    TreeStack stack;
     
    scanf("%d",n);
    stack.top = -1;
    
    // 读取头结点
    scanf("%s",str);    scanf("%d",&data);
    head = (TreeNode)malloc(sizeof(TNode));
    head->data = data;   head->right = NULL;  head->left = NULL;   head->flag = 0;
    current = head;
    stack.data[++stack.top] = head;
    for(i = 0; i < 2*(*n)-1; i++){
        scanf("%s",str);
        if(!strcmp(str,"Push")){
            scanf("%d",&data); 
            temp = (TreeNode)malloc(sizeof(TNode));
            temp->data = data;  temp->left = NULL; temp->right = NULL; temp->flag = 0;
            if(current->left == NULL){
                current->left = temp;
            }else if(current->right == NULL){
                current->right = temp;
            }
            current = temp;
            stack.data[++stack.top] = temp;
        }else if(!strcmp(str,"Pop")){
            current = stack.data[stack.top--];
        }else{
            printf("%s,读取数据出现错误",str);
            break;
        }
    }
    return head;
}

int *Postorder(TreeNode head,int n){
    int *result, *r;
    TreeStack stack;
    TreeNode topNode;
    
    stack.top = -1;
    stack.data[++stack.top] = head;
    result = (int *)malloc(n*sizeof(int));
    r = result;
    while(stack.top >= 0){
        topNode = stack.data[stack.top--];
        if(topNode->left != NULL && topNode->left->flag == 0){
            stack.data[++stack.top] = topNode;
            stack.data[++stack.top] = topNode->left;
        }else if(topNode->right != NULL && topNode->right->flag == 0){
            stack.data[++stack.top] = topNode;
            stack.data[++stack.top] = topNode->right;
        }else{
            topNode->flag = 1;
            *r = topNode->data;
            r++;
        }
    }
    return result;
}

void Print(int *result, int n){
    int i;
    for(i = 0; i < n;i++){
        printf("%d",result[i]);
        if(i != n - 1){
            printf(" ");
        }
    }
}

//void PrintTree(TreeNode tree,int n){
//    int front,rear, j;
//    TreeNode *queue, current;
//    
//    queue = (TreeNode *)malloc(n*sizeof(TreeNode));
//    front = -1; rear = -1;
//    
//    queue[++rear] = tree;
//    while(front != rear){
//        current = queue[++front];
//        printf("%d ",current->data);
//        if(current->left != 0){
//            queue[++rear] = current->left;
//        }
//        if(current->right != 0){
//            queue[++rear] = current->right;
//        }
//    }
//}
