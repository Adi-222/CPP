# include<iostream>
using namespace std;


void print(int n,int num){
    if(n == num ){
        cout<<n;
        return ;
    }
    else{
        cout<<n<<endl;
        print(n+1,num);
    }
    
}

int main(){
    int num;
    int n;
    cout<<"Enter the number"<<endl;
    cin>>num;
    cout<<"enter the end"<<endl;
    cin>>n;
    print(num,n);
    return 0;
}