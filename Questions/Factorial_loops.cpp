# include<iostream>
using namespace std;
int main(){
    int n;
    int fact=1;
     cout<<"Enter the number for wich you want to make the factorial"<<endl;
     cin>>n;
    
     for(int i=1;i<=n;i++){
        if(n==0||n==1){
        return 1;
    }
        fact = fact *i;
     }
     cout<<"The factorial of the number is "<<fact<<endl;
}