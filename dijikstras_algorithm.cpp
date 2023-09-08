//Assignment 08 
//Dijikstras Implementation

#include<iostream>
using namespace std ;
#define M 50 


class C {
    //total number of vertices 
    int numver ;
    //total number od edges 
    int edges ;
    //array for visited 
    int visi[M];
    //array for weighted 
    int A[M][M];
    //array for distand
    int dis[M];
    //current vertex 
    int curr ;

    public :
    void accept_graph();
    void display_matrix();
    void dijikstras_(int);

};


void C ::accept_graph(){
    //taking the number of vertices 
    cout<<"Enter the number of vertices your graph has ";
    cin >> numver ;
    //taking the number of edges 
    cout<<"Enter the number of edges your graph has ";
    cin >> edges ;
    //Loop to insert weight 
    for(int i=0 ; i<edges ; i++){
        int si ;
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
        for (int j=0 ; j<edges ; j++){
               cout<<" "<<i<<" "<<j<<' '<<A[i][j]<<" "<<endl; 
        }
    }
}


void C ::dijikstras_(int source ){
    int j ;

    //array to store parent 
    int p[M];
    //Array 
    int arr[M][M];
   
    for(int i=0 ; i<numver ; i++){
        for(int j=0 ; j<numver ; j++){
            if(A[i][j]==0)
            arr[i][j] = 32767 ;
            else 
            arr[i][j] = A[i][j];
        }
    }

    for(int i=0 ; i<numver ; i++){
        visi[i]= 0  ;
        p[i] = source ;
        dis[i] = arr[source][i];
    }
 
    //set current to source 
    curr = source ;
    //mark source as visited 
    visi[curr] = 1;
     //mark the source distance 
    dis[source] = 0 ;
    
    int count_of_ver  = numver; 

    while(count_of_ver >0 ){
         //initaialize minimum 
        int min = 32767 ;

        for(int j=0 ; j<numver ; j++){
            //only when it is not visited and
            //has minimum distance than the assigned distance 
            if(visi[j]==0  &&  dis[j]<min){
                //update the minimum distance 
                min = dis[j];
                //update the current as well 
                curr = j ;
            }
        }
        //mark the current as visited 
        visi[curr] = 1 ;

        for(int k=0 ; k<numver ; k++){
            //compare the distance calculated with the distance stored 
            //only if its visited and result is smaller 
            if(visi[k]==0 && (min + arr[curr][k]) <dis[k]){
                //update the distance with the minimum 
                dis[k] = min + arr[curr][k] ;
                //update the parent as well 
                p[k] = curr ;
            }
        }
        count_of_ver -- ;
    }
   

    //shortest distance from source 
    for(int i=0; i<numver ; i++){
        cout<<" Distance of   "<<i <<"  "<<" from "<< source <<" is "<<dis[i]<<endl;
        cout<<"Path "<< i ;
        j = i ;
        do{
            j = p[j];
            cout<< " to "<< j;
        }while(j != source );
    }
}


int main(){
    C c ;
    cout<<"Implementation of Dijikstras algorithm "<<endl;
    c.accept_graph();
    c.display_matrix();

    int source ;
    cout<<"Enter the source vertex ";
    cin >> source ;

    c.dijikstras_(source);
    
}