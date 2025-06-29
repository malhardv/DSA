#include<iostream>
#include<unordered_map>
using namespace std;

void countCharacters(unordered_map<char, int> &freq, string input) {
    if(input.size() == 0) return;

    for(char c: input) {
        freq[c]++;
    }
}

int main() {

    string input = "Malhar";
    unordered_map<char, int> freq;
    countCharacters(freq, input);

    for(auto i : freq) {
        cout<<i.first<<" -> "<<i.second<<endl;
    }

    return 0;
}