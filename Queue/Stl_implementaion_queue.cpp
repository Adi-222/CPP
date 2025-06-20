# include<iostream>
# include<queue>
using namespace std;
int main(){
    queue<int>q;
    q.push(30);
    q.push(50);

    cout<<"Display    :"<<q.size()<<endl;
    q.pop();
    cout<<"Display     :"<<q.size()<<endl;

}
