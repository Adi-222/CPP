# include<iostream>
using namespace std;
void printarray(int arr[],int size){
    for(int i=0;i<=size;i++){
        cout<<arr[i]<<endl;
    }
    cout<<"sucessfully printed the array"<<endl;
}
int main(){
    int ten[10] = {1,2,3,4,5,6,7,8,9,0};
    printarray(ten,10);
    

    int tensize = sizeof(ten)/sizeof(int);
    cout<<"The size of array is"<<tensize<<endl;

    return 0;
}
