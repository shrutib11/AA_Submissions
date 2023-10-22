#include <bits/stdc++.h>

using namespace std;

int patternMatching(string str, string pattern){
	int n = str.length();
	int m = pattern.length();
	//cout << n << " " << m << endl;
   
   	int s, j;
   	for(s = 0; s <= (n - m); s++){
		for(j = 0; j < m; j++){
			if(str[s + j] != pattern[j]) 
				break;
		}
		if(j == m){
			cout << "Pattern occurs with shift = " << s;
			return s;
		}
   	}
   	return -1;
}

int main()
{
	string str, pattern;
	cout << "Enter a string : " << endl;
	// cin >> str;
   getline(cin, str);
	cout << "Enter pattern : " << endl;
	//cin >> pattern;
	getline(cin, pattern);
	cout << "Pattern occures with shift = " << patternMatching(str, pattern);
	return 0;
}
