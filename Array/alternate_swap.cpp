# include<iostream>
using namespace std;
void swapalt(int arr[],int size){
    for(int i;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }
}
void printarr(int arr[],int size){
    for(int i = 0; i<size ; i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arrodd[5]={0,9,8,7,90};
    int arreven[6]={12,23,1,2,4,6};

    swapalt(arrodd,5);
    printarr(arrodd,5);
    cout<<endl;


    swapalt(arreven,6);
    printarr(arreven,6);
    cout<<endl;

return 0;

}