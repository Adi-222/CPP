# include<iostream>
# include<vector>
using namespace std;
int main(){
    vector<int>v;

    v.push_back(2);
    v.push_back(18);
    v.push_back(21);
    v.push_back(34);
    v.push_back(12);
    v.push_back(23);
    v.push_back(90);
     
     for(int i =0;i<v.size()-1;i++){
        cin>>v[i];
     }
     for(int i =0;i<v.size()-1;i++){
        cout<<v[i];
     }


    
}
