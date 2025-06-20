# include<iostream>
using namespace std;
int main(){
    int arr[10]={22,3,8,1,32,33,43,45,65,76};
    for(int i =0;i<9;i++){
        int minindex =i;
        for(int j=i+1;j<10;j++){
            if(arr[j]<minindex){
                minindex = j;
            }
        }
        swap(arr[minindex],arr[i]);
    }

}