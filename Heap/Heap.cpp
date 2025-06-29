# include<iostream>
using namespace std;
# include<queue>




class heap{

    public:

    int arr[100];
    int size ;

    heap(){
        arr[0] = -1;
         size = 0;
           
    }



    void insert(int val){
        size = size +1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }


    void print(){
        for(int i =1;i<= size;i++){
            cout<<arr[i] <<" "; 
        }cout<<endl;
    }


    void deleteFromHeap(){

        if(size == 0){
            cout<<"The heap is empty"<<endl;
            return;
        }
        
        arr[1] = arr[size];
        size--;

        int i = 1;

        while(i < size){
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            if(leftindex < size  && arr[i] < arr[leftindex]){
                
                swap(arr[i],arr[leftindex]);
                i = leftindex;
            }
            else if(rightindex < size && arr[i] < arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i = rightindex;
            }
            else{
                return;
            }

        }

    }

};

void heapify(int arr[], int n,int i){

    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
       largest = left;
    }

    if(right <= n && arr[largest]< arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr ,n, largest);
    }

}



void heapSort(int arr[],int n){
    int size = n;

    while(size > 1){
        swap(arr[size],arr[1]);
        size--;


        heapify(arr,size,1);
    }
}


int main(){

    heap h;

    h.insert(5);
    h.insert(6);

    h.print();
    h.deleteFromHeap();
     h.print();


    int arr[6] = {-1, 54,53,55,52,50};
    int n = 5;
    for(int i = n/2; i >0; i--){
        heapify(arr,n,i);
    }

    cout<<"Printing the array Now"<< endl;
    for(int i =1;i<=n;i++){
        cout<<arr[i] << " ";

    }cout<<endl;


    heapSort(arr,n);


    cout<<"Printing the sorted array"<< endl;
    for(int i =1;i<=n;i++){
        cout<<arr[i] << " ";

    }cout<<endl;



    // max heap --> Priority_queue;

    priority_queue<int>pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(6);


    cout<<"Element at the top"<< pq.top()<<endl;
    pq.pop();

    cout<<"Element at the top"<< pq.top()<<endl;


    cout<<"The size of queue"<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"pq is empty"<<endl;

    }else{
        cout<<"Pq is not empty"<<endl;
    }









    return 0;
}