/*
This problem was asked by Amazon.

Given a string, find the length of the smallest window that contains every distinct character. 
Characters may appear more than once in the window.

For example, given "jiujitsu", you should return 5, corresponding to the final five letters.
*/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

string findSubString(string str){
    unordered_set<char> s;
    int n = str.length();
    string res;
    int size = INT_MAX;
    for(int i = 0; i < n; i++){
        s.insert(str[i]);
    }
    int dist_char_count = s.size();

    for(int i = 0; i < n; i++){
        unordered_set<char> s;
        string substr = "";
        for(int j = i; j < n; j++){
            s.insert(str[j]);
            substr += str[j];
            if(s.size() == dist_char_count) break;
        }
        // Make sure the "substr" length's better than previous one (i.e., < size) and 
        // has got all distinct characters in it (i.e., s.size() == dist_char_count)
        if(substr.length() < size && s.size() == dist_char_count){
            res = substr;
            size = res.length();
        }
    }
    return res;
}
// Logic: Sliding Window Technique
string findSubString_optimized(string str){
    unordered_set<char> s;
    int n = str.length();

     for(int i = 0; i < n; i++){
        s.insert(str[i]);
    }
    int dist_char_count = s.size();

    /* ------------------------------- */
// In this problem the window's start is represented by variable "start" and its end is represented by "window_len + start"
    int start = 0, start_index = -1;
    int min_len = INT_MAX, count = 0;
    int char_count[256] = {0};
    for(int i = 0; i < n; i++){
        char_count[str[i]]++;
        if(char_count[str[i]] == 1) count++;
        // We enter this condition only after we have traversed through part of the string (ex: upto 'aabcbcd' in 'aabcbcdbca' )
        // (upto 'jiujit' in 'jiujitsu')
        // which consists of all distinct characters (look at above 'if' case)
        if(count == dist_char_count){
            while(char_count[str[start]] > 1){
                if(char_count[str[start]] > 1) char_count[str[start]]--;
                // Here, we are moving the window (imagine a window on the string) to the left 
                start++;
            }
            // Note that in this problem, our window size here is fixed (i.e., equal to dist_char_count)
            // Here, we are moving the same window(imagine a window on the string) to the right
            int window_len = i - start + 1;
            // This condition implies that we are trying to choose the best window
            if(min_len >= window_len){
                min_len = window_len;
                start_index = start;
            }

        }
    }
    string res = str.substr(start_index, min_len);
    return res;
}

int main(){
    // string str = "CCCbAbbBbbC";
    // string str = "jiujitsu";
    string str = "aabcbcdbca";
    cout << findSubString_optimized(str) << endl;
}

