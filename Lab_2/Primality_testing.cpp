#include <iostream>

using namespace std;

long int gcd(long int a, long int b){
	long int r;
	while(b > 0){
    	r = a % b;
    	a = b;
    	b = r;
	}
	return a;
}

long int power(long int x, long long int y, long long int n){
	long long int res = 1;
	for(int i = 1; i <= y; i++){
    	res = (res * x) % n;
	}
	return res;
}

int isPrime(long long int n, int k){
	int i = 1;
	if(n <= 1 || n == 4){
    	return 0;
	}
	if(n == 2 || n == 3){
    	return 1;
	}
	long long int a;
	while(i <= k){
    	a = 2 + (rand() % (n - 3));
    	if(gcd(a, n) != 1){
        	return 0;
    	}
    	if(power(a, n-1, n) != 1){
        	return 0;
    	}
    	i++;
	}
	return 1;
}

int main()
{
	srand(time(0));
	cout << isPrime(1000000007, 10);
	return 0;
}
