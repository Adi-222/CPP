# include<iostream>
using namespace std;
void reachhome(int src,int dst){
    cout<<src<< " "<<dst<<endl;
    if (src == dst){
        cout<< "reached home"<<endl;
        return ;

    }
    src++;

    reachhome(src,dst);
}

int main(){
    int src = 1;
    int dst = 10;

    reachhome(src,dst);
}