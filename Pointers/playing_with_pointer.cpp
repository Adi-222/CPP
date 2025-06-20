# include<iostream>
using namespace std;
int main(){
    int i=5;
    int * ptr = &i;
    cout<<ptr<<endl;
    cout<<&i<<endl;
    cout<<*ptr<<endl;
    return 0;
}
