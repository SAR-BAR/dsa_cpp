//Assignment 05 
//Binary Search Tree and Traversal
#include<iostream>
using namespace std ;
#define num 50 


//declaration of structure 
struct node{
    int data ;
    struct node*l ;
    struct node *r ;
};


//declaration of class 
class C {
    struct node* root ;
    int top = -1  ;
    struct node* S[num];
    public:
    C (){
        root =NULL ;
    }
    struct node* get_address();
    struct node* create_node(int);
    void insert_node(int);
    struct node* insert_nonre(int);
    struct node* search_by_value(struct node* , int);
    struct node* mirror(struct node*);
    void inorder_nonrecursive(struct node*);
    void postorder_nonrecursive(struct node*);
    void preorder_nonrecursive(struct node*);
    void inorder(struct node*);
    void postorder(struct node*);
    void preorder(struct node*);
    void push(struct node*);
    bool isEmpty();
    bool isFull();
    struct node* pop();
    struct node* Deletion(struct node* tree , int x);
    void get_leaf_nodes(struct node*);
    int get_depth(struct node*);
};


inline struct node* C ::get_address(){
    return root ;
}


bool C ::isEmpty(){
    if(top==-1) return true ;
    else return false ;
}


bool C ::isFull(){
    if(top == num )return true ;
    else return false ;
}


struct node* C ::pop(){
    if(isEmpty()==true){
        cout<<"The stack is empty "<<endl;
    }else {
        struct node* o ;
        o = S[top];
        top -- ;
        return o ;
    }
    
}


void C ::push(struct node* a ){
    if(isFull()==true){
        cout<<"The stack is already full "<<endl;
    }else {
        top ++ ;
        S[top]=a ;
    }
}



struct node* C :: Deletion(struct node* rootr , int x){
    if(rootr ==NULL ){
        return rootr ;
    }else if(x <rootr->data){
         rootr->l = Deletion(rootr->l , x);
    }else if(x > rootr->data){
        rootr->r = Deletion(rootr->r , x);
    }
    //node deletion 
    else {
        //for leaf node
        if(rootr->l==NULL && rootr->r==NULL){
            delete(rootr);
            rootr=NULL;
            return rootr ;
        }
        //for one child 
        else if(rootr->l==NULL){
            struct node* temp ;
            temp = rootr;
            rootr = rootr->r;
            delete(temp);
            return rootr;
        }
        else if(rootr->r==NULL){
              struct node* temp ;
            temp = rootr;
            rootr = rootr->l;
            delete(temp);
            return rootr;

        }
        //for 2 childs 
        else {
            struct node* temp ;
            temp = rootr->r;
            while(temp ->l !=NULL){
                temp = temp->l;
            }
            rootr->data = temp->data;
            rootr->r = Deletion(rootr->r, temp->data);
        }
        
    }
    return rootr;
}


struct node* C ::create_node(int x){
    //make a pointer 
    struct node*t ;
    //allocate memory 
    t = new (node);
    //assign value 
    t->data = x;
    //make left and right of the node null
    t->l=NULL ;
    t->r=NULL ;
    //return the pointer
    return t ;
}


void C ::insert_node(int x){
    struct node* p , *q ;
    
    //check for root
    if(root==NULL){
        cout<<"The root is null . Creating a node for root  "<<endl;
        //calling create fuction
        root = create_node(x);
        //returning the pointer
       
    }
    else {
        p = root ;
        q = root ;
         while(q!=NULL && x!=p->data){
        //to store the address of parent , the q will move forward to the child node and p will hold parent add
        p=q ;
        if(x<q->data){
            q = q->l ;
        }else if(x> q->data){
            q = q->r ;
        }else if(x==q->data){
            //checking for duplicate value 
            cout<<"Duplicate node value "<<endl;   
          //  return q ;
        }
        
    }
    if(x<p->data){
       // p = p->l;
        p->l = create_node(x);
    }else {
       // p = p->r;
        p->r = create_node(x);
    }
   // return p ;
    }
}    


//recursive function
void C ::inorder(struct node* rootp){
    if(rootp!=NULL){
        inorder(rootp->l);
        cout<< rootp->data<<" ";
        inorder(rootp->r);
    }
}


//recursive function
void C ::postorder(struct node* rt ){
    if(rt !=NULL){
        postorder(rt->l);
        postorder(rt->r);
        cout<< rt->data<<" ";
    }
}


//recursive function
void C ::preorder(struct node * rt ){
    if(rt !=NULL){
        cout<< rt->data<<" ";
        preorder(rt->l);
        preorder(rt->r);
    }
    
}


void C ::inorder_nonrecursive(struct node* ro){
    if(ro==NULL){
        cout<<"The tree is empty "<<endl;
    }else {
        struct node* p;
        p = ro ;
        do{
            //go till the leftmost
            while(p !=NULL){
                push(p);
                p = p->l;

            }
            //now if the stack is not empty 
            if( !isEmpty()){
                p = pop();
                cout<<p->data<<" " ;
                p = p->r;
            }
        }while(p !=NULL || !isEmpty() );
}
}


void C ::postorder_nonrecursive(struct node* t){
    if(t==NULL){
        cout<<"The tree is empty "<<endl;
    }else {
       struct node* curr ;
       //make it point to root 
       curr = t ;
       while(curr !=NULL || !isEmpty()){
        //go to the leftmost 
        if(curr !=NULL){
            push(curr);
            curr = curr->l;
        }else {
            struct node* prevn ;
            prevn = S[top]->r;

            //if prev turns out to be null
            if(prevn==NULL){
                prevn = S[top];
                pop();
                cout<< prevn->data<<" ";

                while(!isEmpty() && prevn==S[top]->r){
                    prevn = S[top];
                    pop();
                    cout<< prevn->data<<" ";
                }
                //if prev is not null ...make it equal to current 
            }else curr = prevn ;
        }
       }
    }
}


void C ::preorder_nonrecursive(struct node* rt){
    if(rt==NULL){
        cout<<"Empty tree "<<endl;
        return;
    }else {
        push(rt);
        //loop until stack become empty 
        while(!isEmpty()){
            struct node* d ;
            d = S[top];
            pop();
            cout<< d->data<<" ";
            //push the right child before left child 
            if(d->r) push(d->r);
            if(d->l) push(d->l);

        }
    }
}


//recursice function
struct node* C ::search_by_value(struct node* rootx , int x){
      struct node * p ;
    if(rootx==NULL){
        cout<<"The tree is empty "<<endl;
        return rootx;
    }
     if(rootx->data==x){
        cout<<"Data found "<<endl;
        cout<<"The node having value "<<rootx->data <<endl;
        return rootx;
    }else {
        if(rootx->data<x){
            return search_by_value(rootx->r , x);
        }else {
            return search_by_value(rootx->l , x);
        }
    }
}


//recursive function
struct node* C ::mirror(struct node* rootm ){
    
    
        if(rootm){
             //make a pointer 
        struct node* temp ;
         //make it point to root 
        temp = rootm ;
        //swap the right and left 
        struct node*b ;
        b = temp->r ;
        temp->r = temp ->l ;
        temp ->l = b ;

        //call the function 
        mirror(temp->l);
        mirror(temp->r);
        }
         return rootm ;
    
}


//recursive function
void C ::get_leaf_nodes(struct node* m){
    int i ;
    if(!m) return ;
    if(m->r==NULL && m->l==NULL){
        cout<< m->data <<" ";
        i++;
        return ;
    }
    if(m->r){
        get_leaf_nodes(m->r);
    }
    if(m->l){
        get_leaf_nodes(m->l);
    }

}


int C :: get_depth(struct node* r){
    if(r==NULL){
        return -1 ;
    }else {
        return 1 + max(get_depth(r->l) , get_depth(r->r));
    }
}


int main(){
    C c ;
    int l;
    int f ;
    do{ 
        int xm ;
        cout<<"Enter element ";
        cin >> xm ;
        struct node* m ;
         c.insert_node(xm);
        cout<<"Enter 1 if you want to insert another element ";
        cin >> l ;

    }while(l==1);
    cout<<"Displaying inorder"<<endl;
     c.inorder(c.get_address());
    //c.inorder_nonrecursive(c.get_address());
    do{
        cout<<"Enter the number of operation you want to perform"<<endl;
        cout<<"Enter 1 to search node by value "<<endl;
        cout<<"Enter 2 to get mirror of the tree "<<endl;
        cout<<"Enter 3 to delete node "<<endl;
        cout<<"Enter 4 to traverse through the tree "<<endl;
        cout<<"Enter 5 to get all the leaf nodes of the tree "<<endl;
        cout<<"Enter 6 to get depth of the tree "<<endl;

        int y ;
        cin >> y ;
        switch(y){
            case 1 : {
                cout<<"Searching of a node by its value "<<endl;
                cout<<"Enter the value to be found "<<endl;
                int s ;
                cin >> s ;
                 c.search_by_value(c.get_address() , s);
                break;
            }
            case 2 : {
                cout<<"Mirror of the tree "<<endl;
                c.mirror(c.get_address());
                 cout<<" "<<endl;
                c.inorder(c.get_address());
                break;
            }
            case 3 : {
                cout<<"Deletion of the node "<<endl;
                cout<<"Enter the value of the node to be deleted "<<endl;
                int s ;
                cin >> s;
                c.Deletion(c.get_address(), s);
                cout<<" "<<endl;
                c.inorder(c.get_address());
                break;
            }
            case 4 : {
                int u ;
                do{
                cout<<"Enter the order in which you want to traverse through the tree "<<endl;
                cout<<"Enter 1 for inorder "<<endl;
                cout<<"Enter 2 for postorder "<<endl;
                cout<<"Enter 3 for preorder "<<endl;
                int e ;
                cin >> e;
                switch(e){
                    case 1 : {
                        cout<<"The inorder of the given tree is "<<endl;
                        c.inorder(c.get_address());
                        cout<<" "<<endl;
                        cout<<"Inorder non recursive "<<endl;
                        c.inorder_nonrecursive(c.get_address());
                         cout<<" "<<endl;
                        break;
                    }
                    case 2 : {
                        cout<<"The postorder of the given tree is "<<endl;
                        c.postorder(c.get_address());
                         cout<<" "<<endl;
                        cout<<"Postorder non recursive "<<endl;
                        c.postorder_nonrecursive(c.get_address());
                         cout<<" "<<endl;
                        break;
                    }
                    case 3 : {
                        cout<<"The preorder of the given tree is "<<endl;
                        c.preorder(c.get_address());
                         cout<<" "<<endl;
                        cout<<"Preorder non recursive "<<endl;
                        c.preorder_nonrecursive(c.get_address());
                         cout<<" "<<endl;
                        break;
                    }
                }cout<<"Enter 1 if you want to traverse again "<<endl;
                cin >> u ;
                }while(u==1);
            }
            case 5 : {
                cout<<"Printing all the leaf nodes "<<endl;
                c.get_leaf_nodes(c.get_address());
                 cout<<" "<<endl;
                break;
            }
            case 6 : {
                int h ;
                h = c.get_depth(c.get_address());
                 cout<<" "<<endl;
                cout<<"The depth of the tree is "<< h <<endl;
                break;
            }
        }cout<<"Enter 1 to try another option "<<endl;
        cin >> f ;
        }while(f==1);      
}