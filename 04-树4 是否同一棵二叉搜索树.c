#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 11

typedef struct Node *TreeNode;
typedef struct Node TNode;
struct Node{
    int data;
    TreeNode right;
    TreeNode left;
    int deep;
};

TreeNode buildTree(int n);
int isSame(TreeNode head,int n);
int findDeep(TreeNode head, int i);

int main(){
    int n,l,i;
    TreeNode head;
    scanf("%d",&n);
    while(n != 0){
        scanf("%d",&l);
        head = buildTree(n);
        for(i = 0; i < l; i++){
            if(isSame(head,n))    printf("Yes");
            else printf("No");
            if(i != l - 1)  printf("\n");
        }
        scanf("%d",&n);
        if(n != 0)  printf("\n");
    }
    return 0;
}

TreeNode buildTree(int n){
    int i;
    TreeNode head,current,temp;
    head = (TreeNode)malloc(sizeof(TNode));
    head->right = NULL; head->left = NULL; head->deep = 1;
    scanf("%d",&head->data);
    for(i = 1; i < n; i++){
        current = head;
        temp = (TreeNode)malloc(sizeof(TNode));
        temp->right = NULL; temp->left = NULL; temp->deep = 1;
        scanf("%d",&temp->data);
        while(current != NULL){
            temp->deep++;
            if(current-> data > temp->data){
                if(current -> left == NULL){
                    current->left = temp;
                    break;
                }else   current = current->left;
            }else if(current->data < temp->data){
                if(current->right == NULL){
                    current->right = temp;
                    break;
                }else   current = current->right;
            }
        }
    }
    return head;
}

int isSame(TreeNode head,int n){
    int i = 0;
    TreeNode temp;
    temp = buildTree(n);
    for(i = 1; i <= n;i++){
        if(findDeep(temp,i) != findDeep(head,i)){
            return 0;
        }
    }
    return 1;
}

int findDeep(TreeNode head, int i){
    while(head->data != i){
        while(head->data > i) head = head->left;
        while(head->data < i) head = head->right;
    }
    return head->deep;
}
