# include<iostream>
using namespace std;
int gcd(int a, int b){
    if(a==0){
         return b;
    }
    else if(b==0){
        return a;
    }
    while(a!=b){
        if(a<b){
            b=b-a;
        }
        else{
            a=a-b;
        }
    }
    return a;

}

int main(){
    int a,b;
    cout<<"Enter the numbers";
    cin>>a>>b;
    int ans =gcd(a,b);
    cout<<"The gcd of"<<a<<" and "<<b<<"is "<<ans<<endl;
    return 0;

}