# include<iostream>
using namespace std;
void printsum(int arr [][4],int row,int col){
    
    int sum =0;
    cout<<"Printing the sum "<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            sum = sum +  arr[row][col];
        }
        cout<< sum <<" ";
    }
    cout<<endl;
}
void largestrowsum(int arr[][4],int row,int col){
    int maxi= INT16_MIN;
    int rowindex=-1;
    int sum=0;
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            sum = sum +  arr[row][col];
        }
        if(sum>maxi){
            maxi=sum;
            rowindex = row;
        }
    }
    cout<<"the maximum sum is"<<maxi<<endl;
    
}

int main(){
    int arr[3][4];
    cout<<"Enter the elements int the array :"<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    cout<<"Printing the array"<<endl;
    for(int row = 0;row<3;row++){
        for(int col =0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    printsum(arr,3,4);
    largestrowsum(arr,3,4);
    return 0;
}