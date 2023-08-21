#include <bits/stdc++.h>

using namespace std;
int q = 13;

long long int power(long int a, long long int x, long long int n){
    long long int res = 1;
    while(x > 0){
   	 if(x % 2 == 1){
   		 res = (res * a) % n;
   	 }
   	 x = x / 2;
   	 a = (a * a) % n;
    }
    return res;
}

void Robin_Karp(string T, string P){
	int n = T.length();
	int m = P.length();
    
	int p = 0, t0 = 0;
    
	for(int i = 0; i < m; i++){
    	p = (10 * p + (P[i] - '0')) % q;
   	 
    	//cout << p << " ";
    	t0 = (10 * t0 + (T[i] - '0')) % q;
    	//cout << t0 << " ";
	}
    
	int h = power(10, m-1, q), j;
    
    int flag = 1;
	for(int s = 0; s <= (n-m); s++){
        //cout << p << " " << t0 << endl;
    	if(p == t0){
       	 for(j = 0; j < m; j++){
            if(T[s + j] != P[j]){
                break;
            }
         }      
         //cout << "j is : " << j << " " << m << endl;
         if(j == m) cout << "Pattern found at index : " << s << endl;
    	}

        if(s < n-m){
            t0 = (10 * (t0 - (T[s] - '0') * h) + (T[s + m] - '0')) % q;
        }
        while(t0 < 0) t0 = t0 + q;
	}
    
}

int main()
{
	string str, pattern;
    
    cout << "Enter a string : " << endl;
    getline(cin, str);
    
    cout << "Enter pattern : " << endl;
    getline(cin, pattern);
    
    Robin_Karp(str, pattern);
	return 0;
}
