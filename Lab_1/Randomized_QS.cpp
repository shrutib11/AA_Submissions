Randomized Quicksort

#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int swaps = 0;
int comp = 0;

int Partition(int *arr, int p, int r){
	int x = arr[r];
	int j = p - 1;
	for(int i = p; i < r; i++){
    	comp++;
    	if(arr[i] <= x){
        	j++;
        	swap(arr[i], arr[j]);
        	Swaps++;
    		}
	}
	swap(arr[j + 1], arr[r]);
	swaps++;
	return (j + 1);
}

int Randomized_Partition(int *arr, int p, int r){
	int i = p + (rand() % (r - p + 1));
	swaps++;
	swap(arr[i], arr[r]);
	return (Partition(arr, p, r));
}

void Randomized_QS(int *arr, int p, int r){
	if(p < r){
    	int q = Randomized_Partition(arr, p, r);
    	Randomized_QS(arr, p, q - 1);
    	Randomized_QS(arr, q + 1, r);
	}
}

int main(){
	int n;
	int maxi = 1000;
	cout << "Enter size of array : " ;
	cin >> n;
	srand(time(0));
	int arr[n];
	// //case 1:
	// for(int i = 0; i < n; i++){
	// 	arr[i] = i + 5;
	// }
	//case 2:
	for(int i = 0; i < n; i++){
    	arr[i] = (maxi - 5) - i;
	}
	// //case 3:
	// for(int i = 0; i < n; i++){
	// 	arr[i] = rand() % maxi;
	// }
	cout << "Your array is : " << endl;
	for(int i = 0; i < n; i++){
    		cout << arr[i] << " ";
	}
	cout << endl;
	Randomized_QS(arr, 0, n - 1);
	cout << "Sorted array is : " << endl;
	for(auto i : arr){
     		cout << i << " ";
	}
	cout << endl;
	cout << "Swaps : " << swaps << endl;
	cout << "Comparisions : " << comp << endl;
    return 0;
}



