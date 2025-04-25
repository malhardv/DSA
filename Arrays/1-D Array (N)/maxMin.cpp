#include <iostream>
using namespace std;

int getMax(int num[], int size) {
    int maxi = -100000;

    for (int i = 0; i < size; i++) {

        maxi = max(maxi, num[i]);
        // if (num[i] > maxi) {
        //     maxi = num[i];
        // }
    }
    return maxi;

}


int getMin(int num[], int size) {
    int mini = 10000000;

    for (int i = 0; i < size; i++) {
        mini = min(mini, num[i]);
        // if (num[i] < mini) {
        //     mini = num[i];
        // }
    }
    return mini;
    
}


int main() {
    int size;
    cin >> size;
    int num[100];

    //input array
    for(int i = 0; i < size; i++) {
        cin>>num[i];
    }
    cout<<endl;

    cout << "Maximum value is : " << getMax(num, size) << endl;
    cout << "Minimum value is : " << getMin(num, size) << endl;

    return 0;
}