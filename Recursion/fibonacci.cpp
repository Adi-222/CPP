# include <iostream>
using namespace std;
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
  int ans = fibonacci(n-1)+(n-2);
  return ans;
}
int main(){
    int n;
    cout<<" Enter the numbe for which you want to print fibonacci series"<<endl;
    cin>>n;

    int ans = fibonacci(n);
    cout<<ans<<endl;
}