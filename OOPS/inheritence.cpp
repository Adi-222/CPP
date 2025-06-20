# include<iostream>
using namespace std;

class human{
    public:
    int height;
    int weight;
    int age;

    public:
    int getage(){
        return this->age;

    }
    int setweight(int w){
        return this->weight=w;

    }
};

class male: public human{
    public :
    string color;
    void sleep(){
        cout<<"male is spleeping"<<endl;
    }

};

int main(){
    male object1;
    cout<<object1.age<<endl;
    cout<<object1.height<<endl;
    cout<<object1.weight<<endl;
    


    return 0;
}