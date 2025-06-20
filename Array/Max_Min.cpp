# include<iostream>
using namespace std;
// Creating a function that will give me maximum value for the array
int getmax(int num[],int n){
    int max = INT_MIN;
    for(int i =  0;i<n;i++){
        if (num[i]>max)
        {
            max=num[i];
        }
        
    }
    // maximum value of the array is ready
    return max;
}
int getmin(int num[],int n){
    int min = INT_MAX;
    for(int i =0; i<n; i++){
        if(num[i]<min){
            min=num[i];
        }
    }
     // minimum value of the array is ready
     return min;
}


int main(){

    int size;
    cin>>size;
    int num[100];
    //Taking input in an array
    for(int i = 0;i<size;i++){
        cin>>num[i];
    }
    cout<<"Maximum value of the array is : "<<getmax(num,size)<<endl;
    
    cout<<"Minium value of the array is : "<<getmin(num ,size)<<endl;

    cout<<"program finished"<<endl;
}