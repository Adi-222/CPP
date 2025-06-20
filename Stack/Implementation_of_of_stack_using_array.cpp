# include<iostream>
using namespace std;

class stack{
    public :

    int*arr;
    int top;
    int size;

    stack(int size){
        this -> size = size;//construstor is initialising the size of the array
        arr = new int [size];//memory allocate krwa diya array k
        top = -1;
    }

    void push(int element){
        if(size - top >1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack overflow"<<endl;

        }

    }

    void pop(){
        if(top>=0){
            top--;
            

        }
        else{
            cout<<"Stack underflow"<<endl;

        }

    }

    int peek(){
        if(top>=0){
            return arr[top];

        }
        else{
            cout<<"The Stack is empty"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if(top==-1){
            return true;

        }
        else{
            return false;
        }
    }

};


int main(){
    stack st(8);

    st.push(1);
    st.push(3);
    st.push(4);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    return 0;
}