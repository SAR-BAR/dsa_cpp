//Assignment 06
//Threaded Binary Tree  
#include<iostream>
using namespace std ;

//Defining structure for nodes 
struct node {
    int data ;
    struct node* lchild ;
    struct node* rchild ;
    bool lt ;
    bool rt ;
};


//Defining class 
class C {
    //pointer for head
    struct node* head ;
    //pointer for root 
    struct node* root ;

    public :
    C();
    struct node* get_head();
    struct node* create_node(int);
    struct node* insert_node(int);
    void inorder_nonrecursive(struct node*r);
    void inorder_n(struct node* r);
    void preorder_nonrecursive(struct node* r);
    

};


C ::C(){
    //create head node 
    head = create_node(-999);
}


inline struct node* C ::get_head(){
    return head ;
}


struct node* C ::create_node(int x){
    //make a new node 
    struct node* newn ;
    //allocate memory 
    newn = new node();
    //assign data to it 
    newn->data = x;
    //update its childs 
    newn->lchild = newn ;
    newn->rchild = newn ;
    //update its threads 
    newn->lt = false ;
    newn ->rt = false ;
    //return the node 
    return newn ;
}


struct node* C ::insert_node(int x ){
    struct node* p;
    //check if the head has been created 
    if(head==NULL){
        cout<<"No head has created "<<endl;
        head = create_node(-999);
        //return head 
        return head ;
    }else{
        //check whether root has been created or not 
        if(head->lt ==false ){
        cout<<"Creating a root node "<<endl;
        //make a root node 
        root = create_node(x);
        //modify its children 
        root->rchild = head->rchild;
        head ->lchild = root ;
        //modify its threads 
        head ->lt = true ;
        //return root node 
        return root ;
    }else {
         //pointer p to hold now root 
        p = head->lchild ;
        while(root !=NULL){
            //the pointer p is pointing to root 
        if(p->data >x){
            if(p->lt == false){
                cout<<"The value is smaller than root ";
                struct node* q ;
                q = create_node(x);
                //modify its childrean
                q->lchild = p->lchild;
                q->rchild = p;
                p->lchild = q;
                p->lt = true ;
                break;
            }else {
                p = p->lchild;
            }
        }
        if(p->data <x ){
            if(p->rt == false){
                cout<<"The value is bigger than root ";
                struct node* q;
                q = create_node(x);
                //modify its children
                q->rchild = p->rchild ;
                q->lchild = p;
                p->rchild = q;
                p->rt = true ;
                break;
            }else {
                p = p->rchild ;
            }
        }
        } 
        cout<<"The node has been created sucessfully "<<endl;   
    }
}
}



//non-recursive function for inorder
void C ::inorder_nonrecursive(struct node* r){
   //check for head 
   if(r==NULL){
    cout<<"The tree is empty "<<endl;
   }else {
    //make a pointer 
    struct node* current ;
    //make it point to root 
    current = root ;
    //check for the thread 
    if(current==NULL){
        cout<<"Empty tree "<<endl;
    }else {
         while(current->lt==true){
        current = current->lchild ;
    }
    //start with the inorder
    while(current!=head){
        //display the data 
        cout<< current->data<<" ";
        //check if current has right thread 
        if(current->rt==false){
            // thread is present 
            current = current->rchild;
        }else{
            //go to right subtree
            current = current->rchild;
            //go the leftmost in subtree
            while(current->lt ==true){
                current = current->lchild;
            }
        }
        if(current==head){
            break;
        }
    }

    }
   }
}


//non-recursive function for preorder
void C ::preorder_nonrecursive(struct node* r){
    //check if the head is null or not 
    if(r==NULL){
        cout<<"The tree is empty "<<endl;
    }else {
       //make a pointer 
       struct node* current ;
       //make it point to the rrot 
       current = root ;
       //repeat till current reaches head 
       while(current !=head){
        //print the data 
        cout<< current->data<<" ";
        //check for the lefttree
        if(current->lt==true){
            //go to left subtree 
            current = current->lchild;
        } else{
            //check for right subtree 
            while(current->rt==false){
                //go into right subtree
                current = current->rchild;
            }
            //at right most node if exist 
            //consider left first 
            current = current->rchild;
        }
       }    }
}




int main(){
    C c ;
    cout<<"Threded Binary Tree "<<endl;
    int choice , count ;
    do{
        cout<<"Enter 1 to insert node "<<endl;
        cout<<"Enter 2 for inorder traversal "<<endl;
        cout<<"Enter 3 for preorder traversal "<<endl;
        cin >> choice ;
        switch(choice ){
            case 1 : {
                int y ;
                int x ;
                cout<<"Insertion of node "<<endl;
                do{
                    cout<<"Enter the value to be stored "<<" ";
                    cin >> x;
                    c.insert_node(x);
                    cout<<"Enter 1 to store another node "<<" ";
                    cin >> y;
                }while(y==1);
                break;
            }
            case 2 : {
                cout<<"Inorder traversal "<<endl;
                c.inorder_nonrecursive(c.get_head());
                break;
            }
            case 3 : {
                cout<<"Preorder travaersal "<<endl;
                c.preorder_nonrecursive(c.get_head());
                break;
            }
        }
        cout<<"Enter 1 to perforn another activity "<<" ";
        cin >> count ;
    }while(count==1);
}
    