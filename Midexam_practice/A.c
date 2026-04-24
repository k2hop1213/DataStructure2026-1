#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* head = NULL;

node* alloc_node(int a){
    node* p = malloc(sizeof(node));
    p->data = a;
    p->next =NULL;
    return p;
    
}

void add(int a){
    node* p = alloc_node(a);
    if(head == NULL){
        head = p;
    }
    else{
        node* temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp ->next = p;
    }
}

int insertAfter(int a, int b){
    node* t = head;
    while(t!=NULL){
        if(t->data == a)
            break;
        t= t->next;
    }
    if(t==NULL) return 0;
    node* p = alloc_node(b);
    p->next = t->next;
    t->next = p;
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int n1;
        scanf("%d",&n1);
        add(n1);
    }
    int a,b;
    scanf("%d\n%d",&a,&b);
    
    if(insertAfter(a,b)){
        node* temp = head;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp= temp->next;
        }
    }
    else printf("None");
    
    
    return 0;
}
