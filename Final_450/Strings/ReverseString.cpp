#include<bits/stdc++.h>
using namespace std;


void reverseString(string s){
    for(int i = 0; i < s.size(); i++){
        swap(s[i], s[s.size() - i - 1]);
    }
}


// recursion
void reverseStr(string s){
    // base
    if(s.size() == 0) return;
    reverseStr(s.substr(1));
    cout << s[0] << " ";
}

void reverseStrRec(string s, int i){
    if(i >= s.size()) return;
    reverseStrRec(s, i+1);
    cout << s[i];
}


int main(){
    string s = "abcd";
    reverseStrRec(s, 0);
    return 0;
}