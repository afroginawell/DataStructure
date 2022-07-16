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
