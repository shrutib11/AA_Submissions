#include <bits/stdc++.h>
using namespace std;

//assuming we have 2 alphabets in text string and state transition table is given
vector<pair<int, int>>table = {
    {1, 0}, {1, 2}, {1, 3},{1, 0}
};

void StringMatching(string str, string pattern){
    int q = 0;
    int n = str.length();
    int m = pattern.length();

    for(int i = 0; i < n; i++){
        if(str[i] == 'a')
            q = table[q].first;
        else if(str[i] == 'b')
            q = table[q].second;
        if(q == m)cout << "Match found at index :" << " " << i - m + 1 << endl;
    }
}
int main(){
    string str, pattern;
    
    cout << "Enter a string : " << endl;
    getline(cin, str);
    
    cout << "Enter pattern : " << endl;
    getline(cin, pattern);
    
    StringMatching(str, pattern);
    return 0;
}