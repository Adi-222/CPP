# include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the element you want to check in the array"<<endl;

    cin>>n;

    int arr[5];
    for(int i =0;i<5;i++){
        cout<<arr[i];
        
    
    if(arr[i]==n){
            cout<<"the number is present"<<endl;

        }
        else{
            cout<<"the number is absent"<<endl;
        }
    }

    return 0;
}