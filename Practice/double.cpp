# include<iostream>
using namespace std;

int main(){
    int arr[5]={2,2,3,1,1};
    int cnt=0;
    for(int i =0;i<5;i++){
        cout<<arr[i];
        for(int j =0;j<=i;j++){
            cnt++;
        }
    }
    if(cnt>0){
        cout<<cnt;
    }
    else{
        cout<<"Erorr"<<endl;
    }

}