# include<iostream>
using namespace std;
class queue{
    int *arr;
    int front;
    int rear;
    int size;

    public :
    queue(){
        
    size = 1000;
    arr = new int[size]; 
    front = 0;
    rear = 0;


    }

    int enque(int data){
        if(rear == n){
            cout<<"Queue is full"<<endl;
        }

        else{
            arr[rear] = data;
            rear++;
        }
    }

    int deque(){
        if(front == rear){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front]=-1;
            front++;
            if(front == rear){
                front = 0;
                rear =0;
            }
            
        }
        return ans;
    }

    bool isempty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int qfront(){
        if(front == rear){
            return -1;


        }
        else{
           return  arr[front];
        }
    }

};
int main(){

    queue a ;
    a.enque(10);
    a.enque(20);

}