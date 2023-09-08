//Assignment 02
//Expression Conversion

#include<iostream>
#include<cmath>
using namespace std ;
# define max 70 


//declaring node structure
struct node{
    char data ;
    struct node* next ;
};


//class declaration
class C {
     //pointer for top
    struct node* top ;


    //declaring functions
    public:
    void push(char);
    char pop();
    bool isEmpty();
    int priority(char);
    void postfix(char[], int);
    bool Symbols(char);
    bool asso(char);
    void prefix(char[] , int);
    void Display(char[] , int);
    string infix_to_postfix(string);
    string infix_to_prefix(string);
    int evaluate(int , int , char);
    int evaluate_postfix(string);
    int evaluate_prefix(string);
    void empty_stack();

    C(){
        top =NULL;
    }


};


void C ::push(char x){
     //create a new node
    struct node* m ;
    m = new(node);
    //make next null
    m->next = NULL ;
    //allocate data 
    m->data = x;
    //make neext of head as new node
    m->next = top ;
    //move the top pointer
    top = m ;
}


char C :: pop(){
    if(isEmpty()==true){
        return -1 ;
    }else{
        //make a pointer
       struct  node *temp ;
        //let it point to head i.e. top
        temp = top ;
        //make t pointer point to whatever is store in tnext i.e. position of next node
        top= top->next;
        //delete the temp node which is ponting to initial head 
        
        return temp ->data ;
        free(temp);     
        
    } 
    
}


bool C ::isEmpty(){
    if(top==NULL){
        return true ;
    }else return false;
}


//function to check for the operators 
bool C ::Symbols(char x){
    if( x=='+'||x=='-'||x=='*'||x=='/'||x=='^' )
        return true;
    return false;
}


//function to check priority of the operators 
int C ::priority(char x){
      if(x=='^')
        return 3;
    else if(x=='*'||x=='/')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
    return -1;
}


//infix to postfix conversion
string C ::infix_to_postfix(string infix){
    string postfix = "";
    for(int i=0 ; i<infix.length() ; i++){
        //if it is operand
        if(isalpha(infix[i])){
            postfix = postfix + infix[i];
        }else  //if it is operator 
        if(Symbols(infix[i])){
            if((isEmpty()) || top->data == '('){
                push(infix[i]);
            }//checking for priority 
            else if(priority(infix[i]) > priority(top->data)){
                push(infix[i]);
            }else {
                while((!isEmpty()) && ( priority(infix[i]) <= priority(top->data))){
                    postfix = postfix + pop();
                }
                push(infix[i]);
            }
        }
        //conditions for brackets 
        else if(infix[i] == '('){
            push(infix[i]);
        }else if(infix[i] == ')'){
            while(!isEmpty() && top->data !='(')
            postfix = postfix + pop();
            if(top->data == '(')
            pop();
        }else {
            cout<<" "<<infix[i]<<"Character not allowed "<<endl;
        }
    }
    //emptying the stack at the end 
    while(!isEmpty()){
        postfix = postfix + pop();
    }
    return postfix ;
}


//function to convert infix to prefix 
string C ::infix_to_prefix(string infix ){
    string prefix = "";
    string rev = "";
    for(int i=infix.length()-1 ; i>=0 ; i--){
         if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
        rev += infix[i];
    }
    rev = infix_to_postfix(rev);
    for(int i = rev.length()-1 ; i>=0 ; i--){
        prefix = prefix + rev[i];
    }
    return prefix ;
}


//function to calculate current operation 
int C ::evaluate(int a , int b , char op ){
     switch(op){
        case '+':
            return (a+b);
            break;
        case '-':
            return (a-b);
            break;
        case '*':
            return (a*b);
            break;
        case '/':
            return (a/b);
            break;
        case '^':
            return (pow(a,b));
            break;
        default:
            return 0;
        }
    
}


//evaluation for postfix 
int C ::evaluate_postfix(string postfix){
    int result ;
    int op1,op2,val;
    int len = postfix.length();
    for(int i=0 ; i<len ; i++){
        //if it is operand 
          if(isalpha(postfix[i])){
            cout<<"Enter value of "<<postfix[i]<<": ";
            cin>>val;
            push(val);
        }
        else{
            //if it is operator 
            op2=pop();
            op1=pop();
            result=evaluate(op1,op2,postfix[i]);
            push(result);
        }
    }
    return result ;
}


//evaluation for infix 
int C ::evaluate_prefix(string prefix ){
    int result ;
    int op1,op2,val;
    int len = prefix.length();
    for(int i=len-1 ; i>=0;i--){
        //if it is operand 
        if(isalpha(prefix[i])){
            cout<<"Enter value of "<<prefix[i]<<": ";
            cin>>val;
            push(val);
        }
        else{
            //if it is operator 
            op1=pop();
            op2=pop();
            result=evaluate(op1,op2,prefix[i]);
            push(result);
        }
    }
    return result;
}


void C ::empty_stack(){
    while(! isEmpty()){
        int x ;
        x = pop();
    }
}


int main(){
    C c ;
    cout<<"Implementation of expression conversion "<<endl;
    int choice ;
    int count ;
    string expression ;
    //taking input from user 
    cout<<"Enter infix expression : ";
    cin >> expression ;
    string postfix ;
    string prefix ;
    do{
        //menu driven 
        cout<<"Enter 1 for infix to postfix "<<endl;
        cout<<"Enter 2 for infix to prefix "<<endl;
        cin >> choice ;
        switch(choice){
            case 1 : {
                cout<<"The given infix "<< expression <<endl;
                postfix = c.infix_to_postfix(expression);
                cout<<"The postfix of given infix is "<<postfix <<" "<<endl;
                cout<<endl;
                cout<<"The evaluation of infix is "<< c.evaluate_postfix(postfix)<<endl;
                c.empty_stack();
                break;
            }
            case 2 : {
                cout<<"The given infix is "<< expression << endl;
                prefix = c.infix_to_prefix(expression);
                cout<<"The prefix of the given infix is "<< prefix <<" "<<endl;
                 cout<<endl;
                cout<<"The evaluation of infix is "<< c.evaluate_prefix(prefix)<<endl;
                c.empty_stack();
                break;
            }
        }
        cout<<"------------------------------"<<endl;
        cout<<"Enter 1 to perform with another expression ";
        cin >> count ;
    }while(count==1);
              

}