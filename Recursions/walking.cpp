#include<iostream>
using namespace std;

void reachHome(int src, int home) {
    
    // base case
    if(src == home) {
        return;
    }
    cout<<"This is step "<<src<<endl;
    reachHome(src + 1, home);
}


int main(){
    int src = 1;
    int home = 10;

    reachHome(src, home);
}