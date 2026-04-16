#include <iostream>
using namespace std;
#define MAXN 100

struct NODE{
    char info;
    NODE *pNext;
};



//###INSERT CODE HERE -

struct Stack{
NODE* top;
};

void Init(Stack &s){
    s.top=NULL;
}

bool IsEmpty(Stack s){
    return s.top==NULL;
}

void Push(Stack &s,char x){
    NODE* p=new NODE;
    p->info=x;
    p->pNext=s.top;
    s.top=p;
}

char Pop(Stack &s){
    if(!IsEmpty(s)){
        NODE* p=s.top;
        char x=p->info;
        s.top=s.top->pNext;
        delete p;
        return x;
    }
    return '\0';
}

char Top(Stack s){
    if(!IsEmpty(s)){
        return s.top->info;
    }
    return '\0';
}

int Precedence(char op){
    if(op == '^')return 3;
    if(op=='*' || op == '/') return 2;
    if(op=='+' || op == '-') return 1;
    return 0;
}

bool IsOperator(char c){
    return c=='+'||c=='-'||c=='/'||c=='^'||c=='*';
}

void Input_infix(char infix[], int &n){
    n=0;
    char c;
    while(cin>>c && c !='#'){
        infix[n++]=c;
    }
}

void  infix_to_postfix(char infix[], int n, char postfix[], int& m){
    Stack s;
    Init(s);
    m=0;
    for(int i=0;i<n;i++){
        char c=infix[i];
        if(isdigit(c)){
            postfix[m++]=c;
        } else if(c=='('){
            Push(s,c);
        } else if(c==')'){
            while(!IsEmpty(s)&&Top(s)!='('){
                postfix[m++]=Pop(s);
            }
            Pop(s);
        } else if(IsOperator(c)){
            while(!IsEmpty(s)&&Precedence((Top(s))) >= Precedence(c)){
                postfix[m++]=Pop(s);
            }
            Push(s,c);
        }
    }
    while(!IsEmpty(s)){
        postfix[m++]=Pop(s);
    }
}

void Output(char postfix[], int m){
    for(int i=0;i<m;i++){
        cout<<postfix[i];
        if(i != m-1){
            cout<<" ";
        }
    }
    cout<<endl;
}

int main() {
    char infix[MAXN], postfix[MAXN];
    int ni, np;

    Input_infix(infix, ni);

    infix_to_postfix(infix, ni, postfix, np);

    Output(postfix, np);

    return 0;
}
