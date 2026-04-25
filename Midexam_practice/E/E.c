#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    
}node;

node* top = NULL;

int is_empty(){
    return top == NULL;
}

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

int pop(){
    if(is_empty()){
        printf("underflow\n");
        exit(0);
    }
    
    int res = top->data;
    node* temp = top;
    top = top->next;
    free(temp);
    return res;
}

void print_stack(){
    node* temp = top;
    if(top == NULL){
        printf("empty\n");
        
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    
}

int main(){
    
    while(1){
        int n;
        scanf("%d",&n);
        if(n>0){
            push(n);
        }
        else if(n == 0){
            print_stack();
            break;
        }
        else{
            pop();
        }
    }
    
    
    
    return 0;
}

