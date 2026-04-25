#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

int is_empty(){
    
    return front == NULL; 
}

node* alloc_node(int a){
    node* p = malloc(sizeof(node));
    p->data = a;
    p->prev= NULL;
    p->next = NULL;
    return p;
}

int free_node(node* p){
    int res = p->data;
    free(p);
    return res;
}

void add_front(int a){
    node* p = alloc_node(a);
    if(is_empty()){
        front = rear= p;
    }
    else{
        p->next = front;
        front ->prev = p;
        front = p;
    }
}

void add_rear(int a){
    node* p = alloc_node(a);
    if(is_empty()){
        front = rear= p;
    }
    else{
        p->prev = rear;
        rear->next =p;
        rear = p;
    }
}

int delete_front(){
    if(is_empty()){
        printf("underflow\n");
        exit(0);
    }
    
    node* temp = front;
    if(front == rear){
        front = rear = NULL;
    }
    else{
        front = front ->next;
        if(front != NULL)
            front ->prev = NULL;
    }
    
    return free_node(temp);
    
}

int delete_rear(){
    if(is_empty()){
        printf("underflow\n");
        exit(0);
    }
    
    node* temp = rear;
    if(front == rear){
        front = rear = NULL;
    }
    else{
        rear = rear ->prev;
        if(rear != NULL)
            rear->next = NULL;
    }
    
    return free_node(temp);
    
}

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n>0){
            if(n%2){
                add_front(n);
            }
            else add_rear(n);
        }
        else if(n == 0){
            node* temp = front;
            if(is_empty()){
                printf("empty\n");
            }
            else{
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp = temp -> next;
                }
            }
            break;
        }
        else if(n == -1){
            printf("%d\n",delete_front());
        }
        else if(n == -2){
            printf("%d\n",delete_rear());
        }
        
    }
    
    
    
    return 0;
}
