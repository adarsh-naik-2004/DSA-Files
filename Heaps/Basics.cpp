#include <iostream>
using namespace std;

class Heap {
    public:
    int arr[101];
    int size;

    Heap() {
        size=0;
    }

    void insert (int value) {
        size++;
        arr[size] = value;

        int index = size;

        while( index > 1 ) {
            int parent = index / 2;
            if( arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }

    }

    int delete() {
            int ans  = arr[1];
             //replace root node value with last node data
            arr[1] = arr[size];
            size--;

            //place root node ka data on its correct position
            int index = 1;
            while(index < size) {
                int left = 2*index;
                int right = 2*index+1;
                        
                int largest = index;

                        if(left < size && arr[largest] < arr[left] ) {
                                largest = left;
                        }
                        if(right < size && arr[largest] < arr[right] ) {
                                largest = right;
                        }

                        if(largest == index) {
                                //value is at correct position
                                break; 
                        }
                        else {
                                swap(arr[index], arr[largest]);
                                index = largest;
                        } 
                }
                return ans;
        }
};

void heapify(int arr[], int n, int i) {
        int index = i;
        int leftIndex = 2*i;
        int rightIndex = 2*i+1;
        int largest = index;

        if(leftIndex <= n && arr[largest] < arr[leftIndex]) {
                largest = leftIndex;
        }
        if(rightIndex <= n && arr[largest] < arr[rightIndex]) {
                largest = rightIndex;
        }

        if(index != largest) {
                //left ya right child me se koi > hogya currentNode se
                swap(arr[index], arr[largest]);
                index = largest;
                heapify(arr, n, index);
        }
}

void buildHeap(int arr[], int n) {
        for(int i = n/2; i>0; i--) {
                heapify(arr,n, i);
        }
}

void heapSort(int arr[], int n) {
        while(n != 1) {
                swap(arr[1], arr[n--]);
                heapify(arr,n,1);
        }
}

int main() {
  int arr[] = {-1,12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32};
  int n = 11;
  buildHeap(arr, n);

  cout << "printint the heap "<< endl;
  for(int i=0; i<=n; i++) {
          cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr, n);

  cout << endl << "printint the heap "<< endl;
  for(int i=1; i<=n; i++) {
          cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}