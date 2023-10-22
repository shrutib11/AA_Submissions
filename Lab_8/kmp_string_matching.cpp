#include <bits/stdc++.h>
using namespace std;

void string_matching(string pattern, string text, vector<int>&pie){
	int m = pattern.length() - 1;
	int n = text.length() - 1;
	int q = 0, cnt = 0;
	for(int i = 1; i <= n; i++){
    	bool t = pattern[q + 1] != text[i];
    	cnt++;
    	while(q > 0 and t){
        	q = pie[q];
        	t = pattern[q + 1] != text[i];
        	cnt++;
    	}
    	if(!t) q++;
    	if(q == m){
        	cout << "Hit " << i - m << endl;
        	q = pie[q];
    	}
	}
	cout << "Count of matching : " << cnt << endl;
}

//pre processing
void compute_prefix(string pattern, vector<int>&pie){
	int k = 0;
	int cnt = 0;
	int m = pattern.length() - 1;
   
	for(int q = 2; q <= m; q++){
    	bool t = pattern[k + 1] != pattern[q];
    	cnt++;
    	while(k > 0 and t){
        	k = pie[k];
        	t = pattern[k + 1] != pattern[q];
        	cnt++;
    	}
    	if(!t) k++;
    	pie[q] = k;
	}
	// for(int i = 1; i <= m; i++){
	// 	cout << pie[i] << endl;
	// }
	cout << "count : "<<cnt << endl;
}

int main() {
	string pattern = "0aba";
	string text = "0aabaaabaaba";
	vector<int> pie(pattern.length() + 1, 0);
	compute_prefix(pattern, pie);
	string_matching(pattern, text, pie);
	return 0;
}
