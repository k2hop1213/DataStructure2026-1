#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* top = NULL;

node* alloc_node(int a){
    node* p = malloc(sizeof(node));
    p->data = a;
    p->next = NULL;
    return p;
}

void push(int a){
    node* p = alloc_node(a);
    if(top == NULL){
        top = p;
    }
    else{
        p->next = top;
        top = p;
    }
    
}

void print_recur(node* t){
    if(t != NULL){
        print_recur(t->next);
        printf("%d ",t->data);
    }
    
}


int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++){
        int t;
        scanf("%d",&t);
        push(t);
    }
    print_recur(top);
    
}
