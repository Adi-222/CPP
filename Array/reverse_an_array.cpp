# include<iostream>
# include <vector>
using namespace std;
vector<int>reverse(vector <int> v){
    int s=0;
    int e= v.size()-1;
    while(s<=e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}
void print(vector<int>v){
    for(int i = 0;i < v.size();i++){
        cout<<v[i]<<" ";

    }
    cout<<endl;
}
int main(){
    vector<int>v;
    v.push_back(2);
    v.push_back(78);
    v.push_back(34);
    v.push_back(21);
    v.push_back(12);
    v.push_back(8);


    vector<int>ans = reverse(v);
    cout<<"The reversed array is"<<endl;
    print(ans);



    return 0;
}