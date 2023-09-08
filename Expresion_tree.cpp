//Assignment 04
//Expression Tree
#include<iostream>
using namespace std ;
#define max 40 


//Declaring structure
struct node  {
    char data ;
    struct node* l;
    struct node* r;

};


//Declaration of class 
class C {
    //pointer for the root 
    struct node* root ;
    //stack to hold the operands
    struct node* p[max];
    int top =-1 ;

    public:
    void Create_tree();
    struct node* make_node(char);
    void Inorder(struct node* );
    void inorder_nonr(struct node* );
    void postorder(struct node* );
    void postorder_nonr2(struct node* );
    void preorder(struct node* );
    void preorder_nonr(struct node* );
    struct node* Get_addres();
    void push(struct node*);
    struct node* pop();
    bool isEmpty();
    bool isFull();
    bool isOperator(char x );

};


void C ::push(struct node* m ){
    top ++ ;
    p[top] = m ;
}


struct node* C ::pop(){
    struct node* l;
    if(isEmpty()==true){
        cout<<"The stack is empty "<<endl;
    }else{
    
    l = p[top] ;
    top -- ;
    }
    return l ;
}


bool C ::isEmpty(){
    if(top==-1){
        return true ;
    }else return false ;
}


bool C ::isFull(){
    if(top==max){
        return true ;
    }else return false;
}


bool C ::isOperator(char x){
    if(x=='+'||x=='-'|| x=='*'||x=='/'||x=='~'||x=='^')
        return true ;
        else return false ;
}


inline struct node* C ::Get_addres(){
    return root ;
}


struct node* C :: make_node(char s){
    //create a pointer
    struct node* h;
    //allocate memory 
    h = new (node);
    //asign data 
    h->data = s;
    h->l = NULL ;
    h->r = NULL ;
    return h ;
}


void C ::Create_tree(){
    char post[max];
    cout<<"Enter the postfix expression  ";
    cin >> post;
    
    int i=0 ;
    while(post[i]!='\0'){

        if(isalpha(post[i]) ){
            struct node* temp ;
            temp = make_node(post[i]);
            i++ ;
            push(temp);

        }else{
            if(isOperator(post[i])==true){
                struct node* t1 ;
                t1 = make_node(post[i]);
                struct node* t2 = pop();
                struct node* t3 = pop();
                //make subtree
                t1->r = t2 ;
                t1->l = t3 ;
                push(t1);
                i++;
            }else {
                i++ ;
                continue ;
            }
        }

    }
    root = pop();
    

}


//recursive function
void C ::Inorder(struct node* rt ){
    if(rt !=NULL){
        Inorder(rt->l );
        cout<< rt->data;
        Inorder(rt->r );
    }
}


//non recursive function for inorder 
void C ::inorder_nonr(struct node*rt ){
    if(rt==NULL){
        cout<<"The tree is empty "<<endl;
    }else {
        struct node* p;
        p = rt ;
        do{
            while(p !=NULL){
                push(p);
                p = p->l;

            }
            if( !isEmpty()){
                p = pop();
                cout<<p->data<<" " ;
                p = p->r;
            }
        }while(p !=NULL || !isEmpty() );
}
    
}


//recursive function for postorder 
void C ::postorder(struct node* rt ){
    if(rt!=NULL){
        postorder(rt->l );
        postorder(rt->r );
        cout<< rt->data<<" ";
    }
}


//non recursive function for postorder
void C ::postorder_nonr2(struct node* rt ){
     if(rt==NULL){
        cout<<"The tree is empty "<<endl;
    }else {
       struct node* curr ;
       //make it point to root 
       curr = rt ;
       while(curr !=NULL || !isEmpty()){
        if(curr !=NULL){
            push(curr);
            curr = curr->l;
        }else {
            struct node* prevn ;
            prevn = p[top]->r;

            if(prevn==NULL){
                prevn = p[top];
                pop();
                cout<< prevn->data<<" ";

                while(!isEmpty() && prevn==p[top]->r){
                    prevn = p[top];
                    pop();
                    cout<< prevn->data<<" ";
                }
            }else curr = prevn ;
        }
       }
    }
   
}


//recursive function for preorder
void C ::preorder(struct node* rt ){
    if(rt!=NULL){
         cout<< rt->data<<" ";
        preorder(rt->l );
        preorder(rt->r );
    }
}


//non recursive function for preorder 
void C ::preorder_nonr(struct node* rt ){
      if(rt==NULL){
        cout<<"Empty tree "<<endl;
        return;
    }else {
        push(rt);
        //loop until stack become empty 
        while(!isEmpty()){
            struct node* d ;
            d = p[top];
            pop();
            cout<< d->data<<" ";
            //push the right child before left child 
            if(d->r) push(d->r);
            if(d->l) push(d->l);

        }
    }
  
}



int main(){
    C c ;
    struct node* fr ;
    int ch ;
    int count ;
    do{
        cout<<"Enter 1 for inorder traversal "<<endl;
        cout<<"Enter 2 for postorder traversal "<<endl;
        cout<<"Enter 3 for preorder traversal "<<endl;
        cin >> ch ;
        switch(ch){
            case 1 : {
                cout<<"Inorder traversal "<<endl;
                c.Create_tree();
                cout<<"Recursive inoeder "<<endl;
                c.Inorder(c.Get_addres());
                cout<<" "<<endl;
                cout<<"Non recursive inorder "<<endl;
                c.inorder_nonr(c.Get_addres());
                cout<<" "<<endl;
                break;
            }
            case 2 : {
                cout<<"Postorder traversal "<<endl;
                c.Create_tree();
                cout<<"Recursive postorder"<<endl;
                c.postorder(c.Get_addres());
                cout<<" "<<endl;
                cout<<"Non recursive postorder "<<endl;
                c.postorder_nonr2(c.Get_addres());
                cout<<" "<<endl;
                break;
            }
            case 3 : {
                cout<<"Preorder traversal "<<endl;
                c.Create_tree();
                cout<<"Recursive preorder "<<endl;
                c.preorder(c.Get_addres());
                cout<<" "<<endl;
                cout<<"Non recursive preorder "<<endl;
                c.preorder_nonr(c.Get_addres());
                cout<<" "<<endl;
                break;
            }
        }
        cout<<"Enter 1 to perform another activity ";
        cin >> count ;
    }while(count==1);
    
 
}
