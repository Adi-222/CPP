# include<iostream>
using namespace std;

int split(int arr[],int s,int e){
    int piviot = arr[s];

    // count pata krne liye taki piviot ko right place me place kr sake

    int count = 0;
     for(int i = s+1; i<=e;i++){
        if(arr[i]<=piviot){
            count++;
        }
     }

     //now placing the piviot at the right position so by adding the piviot and the count

     int piviotindex = s + count;
     swap(arr[piviotindex],arr[s]);

     // sort the left and right part of the the piviot index 
     int i = s,j =e;
     while(i <= piviotindex && j >= piviotindex){

        while(arr[i] <= piviotindex){
            i++;
        }

        while(arr[j] > piviotindex){
            j++;
        }
     }

     if(i < piviotindex && j > piviotindex){
        swap(arr[i],arr[j]);
        i++;
        j--;

     }

     return piviotindex;

}

void quicksort(int arr[],int s,int e){
    if(s>=e){
        return ;

    }
    int p;
    p = split(arr,s,e);
    // left wla array ko sort krne ke liye
    quicksort(arr,s,p-1);
    // right wla array ko sort karne ke liye
    quicksort(arr,p+1,e);

}

int main(){
    int arr[6]={2,4,1,6,3,8};

    int n = 6;
    cout<<"starting main function"<<endl;
    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
    cout<<"ending main function"<<endl;
    return 0;
}