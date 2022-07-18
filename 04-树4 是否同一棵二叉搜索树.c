给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。随后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
Yes
No
No
鸣谢青岛大学周强老师补充测试数据！

代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB

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
