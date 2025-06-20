# include<iostream>
using namespace std;
int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;

    if(a%2==0 & b%2 !=0){
        cout<< a<<b<<endl;

    }
    else{
        cout<<b<<a<<endl;
    }
}