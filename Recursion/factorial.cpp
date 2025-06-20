# include<iostream>
using namespace std;
int factorial(int n){
     
    if(n==0){
        return 1;
    }
    /*int smallerveiw = factorial(n-1);
    int bigeerveiw = n * smallerveiw;
    return bigeerveiw;*/    
    
    return n * factorial(n-1);
}




int main(){
    int n;
    
    cout<<"Enter the number for which you want to print factorial"<<endl;
    cin>>n;
    int ans = factorial(n);

     cout<<ans<<endl;

}