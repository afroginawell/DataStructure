给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。

现给定两棵树，请你判断它们是否是同构的。

输入格式:
输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。

输出格式:
如果两棵树是同构的，输出“Yes”，否则输出“No”。

输入样例1（对应图1）：
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
输出样例1:
Yes
输入样例2（对应图2）：
8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4
输出样例2:
No
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 11;

typedef struct tree *TreePoint;
typedef struct tree Tree;
struct tree{
    char ch;
    int right;
    int left;
};

TreePoint Read(int *len);
void Change(char c, int *a);
int Map(TreePoint t1,TreePoint t2,int len);
int Get(TreePoint t1, char ch, int *index, int len);

int main(){
    
    // 读取
    TreePoint t1,t2;
    int len1,len2;
    t1 = Read(&len1);
    t2 = Read(&len2);
    // 匹配
    if(len1 != len2){
        printf("No\n");
        return 0;
    }
    int flag = Map(t1,t2,len1);
    if(flag == 1){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}

TreePoint Read(int *len){
    int i;
    char c1,c2;
    TreePoint t;
    scanf("%d",len);
    t = (TreePoint)malloc((*len+1)*sizeof(Tree));
    t[0].ch = '0';	t[0].left = 0;	t[0].right = 0;
    for(i = 1; i <= *len; i++){
    	scanf("%c",&c1);	// 读换行符 
        scanf("%c %c %c",&t[i].ch,&c1,&c2);
        Change(c1,&t[i].left);
        Change(c2,&t[i].right);
    }
    return t;
}

void Change(char c, int *a){
    if(c == '-'){
        *a = 0;
    }else{
        *a = c - 48 + 1;
    }
}

int Map(TreePoint t1,TreePoint t2,int len){
    int i,index;
    
    for(i = 1; i <= len;i++){
        if(!Get(t1,t2[i].ch,&index, len)){
            return 0;   // 表示没找到
        }
		if( (t1[t1[index].left].ch == t2[t2[i].left].ch && t1[t1[index].right].ch == t2[t2[i].right].ch) || (t1[t1[index].right].ch == t2[t2[i].left].ch && t1[t1[index].left].ch == t2[t2[i].right].ch)){
			continue;
		}else{
			return 0;
		}
    }
    return 1;
}

int Get(TreePoint t1, char ch, int *index, int len){
    int i ;
    
    for(i = 1; i <= len; i++){
        if(t1[i].ch == ch){
            *index = i;
            return 1;
        }
    }
    return 0;
}
