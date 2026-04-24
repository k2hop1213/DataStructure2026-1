#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 6

int queue[MAX_SIZE];

int front = 0;
int rear = 0;
int real_front = 0;

int is_empty(){
    return real_front == rear;
}
int is_full(){
    return (rear + 1)%MAX_SIZE == real_front;
}

void enqueue(int a){
    if(is_full()){
        printf("Full\n");
    }
    else{
        rear = (rear+1)%MAX_SIZE;
        queue[rear] = a;
    }
}

void dequeue(){
    if(is_empty()){
        printf("Empty\n");
    }
    else{
        real_front = (real_front + 1) % MAX_SIZE;
        front = (real_front + 1) % MAX_SIZE;
    }
}


void print_queue(){
    if(is_empty()){
        printf("Empty\n");
        
    }
    else{
        int i = front;
        while(i!=rear){
            printf("%d ",queue[i]);
            i = (i+1) % MAX_SIZE;
        }
        printf("%d ",queue[i]);
        
    }
    
}

int main(){
    while(1){
        int a;
        scanf("%d",&a);
        
        if(a == 1){
            int b;
            scanf("%d",&b);
            enqueue(b);
        }
        else if(a== 2){
            dequeue();
        }
        else{
            print_queue();
            break;
        }
        
    }
    
    
    
    return 0;
}
