#include <stdio.h>
#include <stdlib.h>
int stack[201];
int top = -1;

void push(int a){
    stack[++top] = a;
}

int pop(){
    return stack[top--];
}


int evaluate_postfix(char* s){
    for(int i = 0;s[i];i++){
        if(s[i]>='0'&&s[i]<='9'){
            char buf[4];
            int idx = 0;
            while(s[i]>='0'&&s[i]<='9'){
                buf[idx++] = s[i++];
            }
            buf[idx]='\0';
            push(atoi(buf));
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'){
            int n2 = pop();
            int n1 = pop();
            if(s[i]=='+') push(n1 + n2);
            else if(s[i]=='-')push(n1 - n2);
            else if(s[i]=='/')push(n1 / n2);
            else if(s[i]=='*')push(n1 * n2);
            
        }
    }
    return stack[top];
}

int main(){
    char str[201];
    gets(str);
    printf("%d ",evaluate_postfix(str));
    
}
