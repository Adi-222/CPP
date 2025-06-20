# include<iostream>
using namespace std;

void merge(int *arr,int s,int e){
    int mid = (s+e)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int [len1];
    int *second = new int [len2];
    
    // copying the values

    int mainindexarray = s;
    for (int i = 0; i<len1;i++){
        first[i] = arr[mainindexarray++];
    }

    int k = mid;
    for (int i = 0;i<len2;i++){
        second[i] = arr[mainindexarray++];
    }

    // merging two sorted array
    int index1 = 0;
    int index2 = 0;
    mainindexarray = s;
    
    while(index1 < len1 && index2 <len2){
        if(first[index1] < second[index2]){
            arr[mainindexarray++] = first[index1++];

        }
        else{
            arr[mainindexarray] = second[index2++];

        }
    }

    while(index1 < len1){
         arr[mainindexarray++] = first[index1++];
    }
    while(index2 < len2){
         arr[mainindexarray] = second[index2++];
    }

}
void mergesort(int *arr,int s,int e){
    int mid = (s+e)/2;
    //base case
    if(s>=e){
        return ;

    }

    //for the left part sorting

    mergesort(arr,s,mid);

    // for sorting right part of the array

    mergesort(arr,mid+1,e);

    //merge both the array

    merge(arr,s,e);

}

int main(){
    int arr[6] = {9,1,8,3,6,2};
    int n = 6;

    mergesort(arr,0,n-1);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;

}
