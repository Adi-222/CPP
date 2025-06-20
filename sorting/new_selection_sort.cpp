# include<iostream>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp =arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    cout<<"Enter the element you want to insert in the array"<<endl;

    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];

    }
    cout<<"The orignal array beafor swapping is"<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i];
    }

    selectionsort(arr,n);

    cout<<"The array after swapping is "<<endl;
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    
}