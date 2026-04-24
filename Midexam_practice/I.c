#include <stdio.h>

typedef struct{
    int n;
    int state;
    int result;
}Frame;

Frame stack[10001];

int top = -1;

void push(Frame f){
    stack[++top] = f;
}

Frame pop(){
    return stack[top--];
}

Frame* peek(){
    return &stack[top];
}

int fib_stack(int N){
    Frame f = (Frame){N,0,0};
    push(f);
    int res = 0;
    while(top!=-1){
        Frame* t = peek();
        
        if(t->n<=1){
            res = t->n;
            pop();
        }
        else if(t->state == 0){
            t->state = 1;
            Frame n1= (Frame){t->n-1,0,0};
            push(n1);
        }
        else if(t->state == 1){
            t->state = 2;
            t->result = res;
            Frame n1 = (Frame){t->n-2,0,0};
            push(n1);
        }
        else if (t->state == 2){
            res += t->result;
            pop();
        }
        
        
    }
    
    
    return res;
    
}

int main(){
    
    int n;
    scanf("%d",&n);
    printf("%d",fib_stack(n));
    
    return 0;
}
