#include<iostream>
using namespace std;
 void swap(int a[],int i,int j){
     int temp = a[i];
     a[i]=a[j];
     a[j]=a[i];
 }
int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
for(int i = 0; i<n;i++){
    cout<<arr[i]<<" ";
    
}
return 0;
}