#include <bits/stdc++.h>

using namespace std;
vector<int>shift(26, 0);

void shiftTable(string pattern){
	int m = pattern.length();
	for(int i = 0; i < 26; i++){
    	shift[i] = m;
	}
	for(int i = 0; i <= m - 2; i++){
    	shift[pattern[i] - 'a'] = m - 1 - i;
	}
	// for(int i = 0; i < 28; i++){
	// 	cout  << i << " " << shift[i] << endl;
	// }
}

int patternMatching(string str, string pattern){
	int m = pattern.length();
	int n = str.length();
    cout << m << " " << n << endl;

	int j = 0;
	while(j + m <= n){
    	if(pattern[m - 1] == str[j + m - 1]){
        	int i = m - 2;                                                                  	//second last character
        	while(i >= 0 && pattern[i] == str[j + i]){
            	i--;
        	}
        	if(i == -1)return j;
    	}
        //cout << (str[j + m - 1] - 'a') << " ";
        if(((str[j + m - 1] - 'a') < 26) && ((str[j + m - 1] - 'a') >= 0))
    	    j = j + shift[str[j + m - 1] - 'a'];
        else
            j = j + m;
	}
	return -1;
}

int main()
{
	string str, pattern;
	cout << "Enter a string : " << endl;
	//cin >> str;
	getline(cin, str);
	cout << "Enter pattern : " << endl;
	//cin >> pattern;
	getline(cin, pattern);
	shiftTable(pattern);

	cout << "Pattern occures with shift = " << patternMatching(str, pattern);

	return 0;
}
