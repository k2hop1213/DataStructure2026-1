#include <stdio.h>
#include <stdlib.h>

int* queue = NULL;
int front = 0;
int rear = 0;
int sz = 0;
int is_empty(){
    return front == rear;
}

int is_full(){
    return (rear + 1) % sz == front;
}

void enqueue(int a){
    if(is_full()){
        printf("overflow\n");
        exit(0);
    }
    rear = (rear + 1)%sz;
    queue[rear] = a;
}

int dequeue(){
    if(is_empty()){
        printf("underflow\n");
        exit(0);
    }
    front = (front + 1) % sz;
    return queue[front];
    
}

int peek(){
    if(is_empty()){
        printf("underflow\n");
        exit(0);
    }
    return queue[(front + 1) % sz];
}

int main(){
    scanf("%d",&sz);
    queue = malloc(sizeof(int)*(sz + 1));
    sz = sz + 1;
    while(1){
        int a;
        scanf("%d",&a);
        if(a>0){
            enqueue(a);
        }
        else if (a == 0){
            free(queue);
            return 0;
        }
        else if (a == -1){
            int t =dequeue();
            printf("%d\n",t);
        }
        else if (a == -2){
            int t =peek();
            printf("%d\n",t);
        }
    }
    
    
    return 0;
}
