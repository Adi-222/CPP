# include<iostream>
using namespace std;

bool search(int arr[],int size,int key){
    for(int i = 0;i<size;i++){
        if(arr[i]== key){
            return 1;
        }
    }
    return 0;
}
int main(){
    int arr[10]={1,3,5,4,2,7,78,89,12,23};
    cout<<"Enter the key"<< endl;
    int key;
    cout<<"key";
    cin>>key;

    bool found = search(arr,10,key);
    if (found){
        cout<<"key is present"<< endl;

    }
    else{
        cout<<"Key is absent "<< endl;

    }

   return 0;
}