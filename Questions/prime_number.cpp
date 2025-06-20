# include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number for which you want to check"<<endl;
    cin>>n;
    if(n<2){
        cout<<"The number is prime"<<endl;

    }
    for(int i =2;i<n;i++){
        if(n%i==0){
            cout<<"The number is not prime"<<endl;
            return 0;
        }
        
    }
    cout<<"The number is prime"<<endl;
    return 0;
}