#include <stdio.h>

char stack[101];
int top = -1;

int is_empty(){
    return top == -1;
}

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

int calculate_vps(char* s){
    top = -1;
    for(int i = 0;s[i];i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            push(s[i]);
        }
        else if(s[i]==')'||s[i]==']'||s[i]=='}'){
            if(is_empty()) return -1;
            if((stack[top] == '(' && s[i]==')')||(stack[top] == '[' && s[i]==']')||(stack[top] == '{' && s[i]=='}')){
                pop();
            }
            else return -1;
        }
    }
    if (!is_empty()) return -1;
    
    top = -1;
    
    int depth = 1;
    int val = 0;
    int res = 0;
    
    for(int i = 0;s[i];i++){
        if(s[i] == '('){
            depth *=2;
            push(s[i]);
        }
        else if(s[i]=='['){
            depth *=3;
            push(s[i]);
        }
        else if(s[i]=='{'){
            depth *=4;
            push(s[i]);
        }
        else{
            if(s[i] == ')'){
                val = depth;
                depth /= 2;
                if(s[i-1]==')'||s[i-1]==']'||s[i-1]=='}'){
                    
                }
                else res += val;
                
            }
            else if(s[i]==']'){
                val = depth;
                depth /= 3;
                if(s[i-1]==')'||s[i-1]==']'||s[i-1]=='}'){
                    
                }
                else res += val;
               
            }
            else if(s[i]=='}'){
               val = depth;
                depth /= 4;
                if(s[i-1]==')'||s[i-1]==']'||s[i-1]=='}'){
                    
                }
                else res += val;
               
            }
        }
    }
    return res;
    
    
}



int main(){
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++){
        char buf[101];
        scanf("%s",buf);
        int t =calculate_vps(buf);
        if(t == -1){
            printf("INVALID\n");
        }
        else{
            printf("%d\n",t);
        }
    }
    
    
    return 0;
}
