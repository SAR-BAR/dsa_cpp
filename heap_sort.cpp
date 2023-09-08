//Assignment 09 
//implementation of heap sort 
#include<iostream>
using namespace std ;


//recursive function
void heapify(int arr[] , int n , int root ){
    int largest = root ;
    int lc = 2*root +1 ;
    int rc = 2*root + 2;
    //if lc is larger than root 
    if(lc <n && arr[lc] > arr[largest]){
        largest = lc ;
    }
    //if rc is larger than root 
    if(rc <n && arr[rc] > arr[largest]){
        largest = rc ;
    }
    //if largest is is not root 
    if(largest !=root){
        swap(arr[root] , arr[largest]);
        heapify(arr , n , largest);
    }
    //recursively call heapify
}


//function to display array
void display(int arr[], int n ){
    
    for(int i=0 ; i<n ; ++i){
        cout<< arr[i]<<" ";
        
    }
    cout<<endl;
}


//function to sort the array
void heap_sort(int arr[] , int n ){
   // build heap 
    for(int i= (n/2)-1 ; i >=0 ; i--){
        heapify(arr , n , i);
    }
    //one by one extract an element 
    for(int i= n-1 ; i>=0 ; i--){
        swap(arr[0] , arr[i]);
        heapify(arr , i , 0);
        display(arr , n);
    }
}


int main(){
    cout<<"Implementation of heap algorithm "<<endl;
    cout<<"Enter the number of elements you want to enter ";
    int n ;
    cin >> n;

    int arr[10];
    cout<<"Enter the elements "<<endl;
    for(int i=0 ; i<n ; i++){
        cout<<"Enter the element ";
        cin >> arr[i];
    }
    cout<<"Using max heap "<<endl;
    heap_sort(arr , n);
}