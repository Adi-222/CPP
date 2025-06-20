# include<iostream>
using namespace std;
class hero{
    private:
    int health;
    public:
    char level;
    void print(){
        cout<<level<<endl;
    }
    int gethealth(){
        return health;
    }
    char getlevel(){
        return level;
    }
    void sethealth(int h){
        health =h;
    }
    void setlevel(char ch){
        level=ch;

    }

};

int main(){
    //static allocation
    hero a;
    a.sethealth(90);
    a.setlevel('B');
    cout<<"level is"<<a.level<<endl;
    cout<<"health is"<<a.gethealth()<<endl;
    //dynamic allocation
    hero *b= new hero;
    b->setlevel('A');
    b->sethealth(40);
    cout<<"level is"<<(*b).level<<endl;
    cout<<"level is"<<(*b).gethealth()<<endl;
    cout<<"level is"<<b->level<<endl;
    cout<<"level is"<<b->gethealth()<<endl;
}