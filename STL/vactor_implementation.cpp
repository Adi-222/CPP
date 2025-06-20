# include<iostream>
# include<vector>

using namespace std;
int main(){

    // creation of vector and taking the user input by push bak operation
    vector<int>v;
    vector<int>v1(5,2);
    cout<<"The size of vector is "<<v.size()<<endl;
    cout<<"The capacity of the vector is "<<v.capacity()<<endl;
    v.push_back(3);
    v.push_back(6);
    v.push_back(10);
    v.push_back(5);
    v.push_back(1);
    v.pop_back();
    cout<<"the size of vector is "<<v.size()<<endl;
    cout<<"The capacity of the vector is "<<v.capacity()<<endl;
    v.clear();
    cout<<"The size of vector is "<<v.size()<<endl;
    cout<<"The Capacity of the vector is "<<v.capacity()<<endl;

    cout<<"The size of vector V1 is"<<v1.size()<<endl;
    cout<<"The Capacity of the vector V1 is "<<v1.capacity()<<endl;

    v1.push_back(6);
    cout<<"The size of the vector v1 after inserting the poush back "<<v1.size()<<endl;
    cout<<"The capacity of the vector v1 is "<<v1.capacity()<<endl;

    v1.pop_back();
    cout<<"The size of the vector v1 after pop back "<<v1.size()<<endl;
    cout<<"The capacity of the vector v1 is "<<v1.capacity()<<endl;

    v1.clear();
    cout<<"The size of the vector v1 after erase "<<v1.size()<<endl;
    cout<<"The capacity of the vector v1 is "<<v1.capacity()<<endl;







}