//Assignmnet 07 
//Minimum Spanning Tree using Prim's Algorithm and Kruskal's Algorithm

#include<iostream>
using namespace std ;
#define M 60


class C {
    //number of vertices 
    int n ;
    //numbet of edges 
    int edges ;
    //weight of edgs 
    int A[M][M];
    //To store parent of vertex
    int parent[M];
    

    public :
    //Constructor
    C();

    //Methods for graph input 
    void accept_graph();
    void display_matrix();

    //Function for prim's 
    int prims();

    //Functions for Kruskal's
    int kruskals();
    int find_K(int);
    void form_union(int i , int j );
    
};


C ::C(){
   for(int  i=0 ;  i<n ; i++){
    for(int j=0 ; j<n ; j++){
        A[i][j]= 0;
    }
   }
}


int C ::prims(){
    //Initialisation for prims algorithm
    //visited or not 
    int visi[n] ;
    //for vertices  
     int p[n];
       //for storing the distane
    int dis[n];
    for (int i=0 ; i<n ; i++){
        visi[i] = 0;
        p[i]=0;
        dis[i]= 32767 ;

    }
   
    int current = 0 ;
    int totalvisi = 1;
    visi[current]= 1;
    dis[current]= 0;
    int mincost = 32767 ;

    //procedure 
    while(totalvisi != n){
        for (int i=0 ; i<n ; i++){
            dis[i]= mincost ;
        }

        for(int i=0 ; i<n ; i++){
            if(A[current][i] !=0 && visi[i]==0){
                if(dis[i] > A[current][i]){
                    dis[i] = A[current][i];
                    p[i]= current;
                }

            }
        }

        for(int i=0 ; i<n ; i++){
            if(visi[i]==0 && dis[i]<mincost){
                mincost = dis[i];
                current = i ;
            }
        }

        visi[current]= 1;
        totalvisi = totalvisi +1 ;
    }

    mincost = 0;
    for(int i=0 ; i<n ; i++){
        mincost = mincost + dis[i];
    }


    return mincost ;
}


int C ::kruskals(){
    //l is edgecount
    int  l =0 ;
    int a , b ;
    int min ;
    int mincost = 0;
    
  
    for(int i=0 ; i<n ; i++){
        parent[i] = i;
    }

    while(l < n-1){
        min = INT16_MAX  ; 
        a = 0 ;
        b = 0 ;

        for(int i=0 ; i<n ; i++ ){
            for(int j=0 ; j<n ; j++){
                if((find_K(i) != find_K(j)) && (A[i][j] <min)  && A[i][j] != 0 ){
                    min = A[i][j];
                    a = i ;
                    b = j ;
                }
            }
        }
       form_union(a , b);
       l++ ;
       cout <<" "<<a<<" "<<b<<" "<<min << endl;
       mincost = mincost + min ;
    }
return mincost ;
}


//Function to search parent vertex
int C ::find_K( int i){
   while(parent[i] !=i){
    i = parent[i];
   }
   return i ;
}


void C ::form_union(int i , int  j ){
    i = find_K(i);
    j = find_K(j);
    parent[i] = j ;

}


void C ::accept_graph(){
   //Taking number of vertices 
    cout<<"Enter the number of vertices ";
    cin >> n;
    //Taking number od edges 
    cout<<"Enter the numeber of edges  ";
    cin >> edges ;
    //Loop to insert weight 
    for (int i=0 ; i<edges ; i++){
        int si;
        int ei ;
        int weight ;
        cout<<"Enter starting vertex of  edge ";
        cin >> si ;
        cout<<"Enter ending vertex of edge ";
        cin >> ei ;
        cout<<"Enter weight of the edge  ";
        cin >> weight ;
        cout<<"                          "<<endl;
        A[si][ei] = weight ;
        A[ei][si]= weight ;
    }
}


void C ::display_matrix(){
    cout<<"The  current matrix "<<endl;
    for(int i=0 ; i<edges ; i++){
        for (int j=0 ; j<i ; j++){
               cout<<" "<<i<<" "<<j<<' '<<A[i][j]<<" "<<endl; 
        }
    }
}


//Menu driven main function 
int main(){
    cout<<"Implementation  of prims algorithm "<<endl;
    cout<<"-----------------------------------"<<endl;
    C c ;
    c.accept_graph();
    cout<<"The matrix of the given graph "<<endl;
    c.display_matrix();
    cout<<"----------------------------"<<endl;
    int choice , count ;
    do{
        cout<<"Enter 1 to implement prims algorithm "<<endl;
        cout<<"Enter 2 to implement kruskals algorithm "<<endl;
        cin >> choice ;
        switch(choice){
            case 1 : {
                cout<<" by Prims algorithm "<<endl;
                int k ;
                k = c.prims();
                cout<<"The minimum length is "<< k <<endl;
                break;
            }
            case 2 : {
                cout<<" by Kruskals algorithm "<<endl;
                int k ;
                k = c.kruskals();
                cout<<"The minimum length is "<< k <<endl;
                break;
            }
        }
        cout<<"Enter 1 to perform another actiity on graph ";
        cin >> count ;
    }while(count==1);
}