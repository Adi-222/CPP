#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,non;
    cout<<"Enter The no and No od occurence"<<endl;
    cin>>n;
    cin>>non;
    string a;
    a=to_string(n)+" "+to_string(non);
    cout<<"The output"<<a<<endl;
    cout<<"The no. is"<<a.at(0);
    return 0;
}