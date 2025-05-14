#include<iostream>
using namespace std;

class Heap {
    public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity) {
        this -> arr = new int[capacity];
        this -> capacity = capacity;
        // size = current number of elements in heap
        size = 0;
    }

    void insert(int data) {
        if(size == capacity) {
            cout<<"Heap Overflow!"<<endl;
        }

        // 1. Insertion of value
        size++;
        int index = size;
        arr[index] = data;

        // 2. Heapification / Check Position
        while(index > 1) {
            int parent = index/2;
            if(arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    int deleteElement() {
        
        // replacement - (root -> leaf)
        int answer = arr[1];
        arr[1] = arr[size];
        // delete last element from its original position
        size--;

        int index = 1;
        while(index < size) {
            int left = 2 * index;
            int right = (2 * index) + 1;

            int largest = index;

            if(left <= size && arr[largest] < arr[left]) {
                largest = left;
            }

            if(right <= size && arr[largest] < arr[right]) {
                largest = right;
            }

            if(index == largest) {
                break;
            } else {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return answer;
    }

    void printHeap() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] <<" ";
        }
        cout<<endl;  
    }
};

void heapify(int *arr, int n, int index) {
    int leftChild = 2*index;
    int rightChild = (2*index) + 1;

    int largestIndex = index;
    if(leftChild <= n && arr[largestIndex] < arr[leftChild]) {
        largestIndex = leftChild;
    }

    if(rightChild <= n && arr[largestIndex] < arr[rightChild]) {
        largestIndex = rightChild;
    }

    // after the above two conditions, the largestIndex will be pointing towards the largest value.
    if(index != largestIndex) {
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n) {
    for(int index = n/2; index > 0; index--) {
        heapify(arr, n, index);
    }
}

// n = size of array
void heapSort(int arr[], int n) {
    while(n != 1) {
        swap(arr[1], arr[n]);    // not arr[n-1] because 1 based indexing
        n--;
        heapify(arr, n, 1);
    }
}

int main() {
    // Heap h(20);

    // // Insertion
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // cout<<"Printing the heap: "<<endl;
    // h.printHeap();
    // int ans = h.deleteElement();
    // cout<<"Deleted Node: "<<ans<<endl;
    // cout<<"Printing the heap: "<<endl;
    // h.printHeap();

    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    int n = 6;

    buildHeap(arr, n);

    cout<<"Printing Heap: "<<endl;
    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr, n);
    cout<<"Printing Sorted Heap: "<<endl;
    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}