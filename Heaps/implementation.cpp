#include<iostream>
using namespace std;

class Heap {
    public: 
    
    int *arr;
    int size;
    int capacity;

    Heap(int capacity) {
        this -> arr = new int [capacity];
        this -> capacity = capacity;
        this -> size = 0;
    }

    void insertInHeap(int data) {
        // check if heap is full or not
        if(size == capacity) {
            cout<<"Heap Overflow!";
            return;
        }

        // put the element in the available position
        size++;
        int index = size;
        arr[index] = data;

        // take the element to its correct position
        while(index > 1) {
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }

        }
    }

    int deleteRoot() {
        // replace the root element with the rightmost element
        int answer = arr[1];
        arr[1] = arr[size];
        size--;
        int index = 1;

        // take the root element(last) to its correct position
        while(index < size) {
            
            int leftIndex = 2*index;
            int rightIndex = 2*index + 1;
            int largestIndex = index;

            if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]) {
                largestIndex = leftIndex;
            } 

            if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]) {
                largestIndex = rightIndex;
            }

            if(largestIndex == index) {
                break;
            } else {
                swap(arr[largestIndex], arr[index]);
                index = largestIndex;
            }
        }

        return answer;
    }

    void printHeap() {
        for(int i = 1; i <= size; i++) {
            cout<<arr[i]<<" ";
        }
    }
};

void heapify(int arr[], int size, int index) {
    int largestIndex = index;
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;

    if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]) {
        largestIndex = leftIndex;
    }

    if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]) {
        largestIndex = rightIndex;
    }

    if(largestIndex == index) {
        return;
    } else {
        swap(arr[largestIndex], arr[index]);
        index = largestIndex;
        heapify(arr, size, index);
    }
}

void buildHeap(int arr[], int size) {
    for(int i = size/2; i > 0; i--) {
        heapify(arr, size, i);
    }
}

void heapSort(int arr[], int size) {
    while(size != 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}

int main() {
    Heap h(20);
    h.insertInHeap(10);
    h.insertInHeap(5);
    h.insertInHeap(12);
    h.insertInHeap(21);
    h.insertInHeap(35);

    cout<<"Printing Heap: ";
    h.printHeap();
    cout<<endl;

    h.deleteRoot();
    cout<<"Printing Heap Post Deletion: ";
    h.printHeap();
    cout<<endl;

    int arr[] = {-1, 5, 10, 12, 21, 35};
    buildHeap(arr, 5);
    cout<<"The Built Heap is: ";
    for(int i = 1; i <= 5; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, 5);
    cout<<"Sorted Array: ";
    for(int i = 1; i <= 5; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}