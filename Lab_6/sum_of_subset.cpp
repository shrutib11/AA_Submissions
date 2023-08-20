#include<bits/stdc++.h>
using namespace std;

bool Knapsack(vector<vector<int>> & mat, vector<int>&arr, int n, int sum){
    for(int i = 0; i < n+1; i++){
		mat[i][0] = 0;
	} 
	for(int j = 1; j <= sum; j++){
		mat[0][j] = 0;
	}
    for(int i = 1; i < n+1; i++){
		for(int j = 1; j <= sum; j++){
			if(j < arr[i])
				mat[i][j] = mat[i-1][j];
			else
				mat[i][j] = max(mat[i-1][j], mat[i-1][j - arr[i]] + arr[i]);
		}
	} 
    // cout << "Matrix is : " << endl;
    // for(int i = 0; i < n+1; i++){
    //     for(int j = 0; j <= sum; j++){
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
   
    if(mat[n][sum] >= sum)return true;
    else return false;
}

int main(){
    int n;
    cout << "Enter size : " << endl;
    cin >> n;

    int sum;
    cout << "Enter sum : " << endl;
    cin >> sum;
    vector<vector<int>>mat(n+1, vector<int>(sum + 1));

    set<int>s;
    vector<int>arr(n + 1);
    cout << "Enter set : " << endl;
    
    s.insert(0);
    int temp;
    for(int i = 1; i < n+1; i++){
        cin >> temp;
        s.insert(temp);
    }

    int i = 1;
    arr[0] = 0;
    for(auto ele : s){
        arr[i] = ele;
        i++;
    }
    if(Knapsack(mat, arr, n, sum) == true)
        printf("Hurehhh!!!");
    else
        printf("Oops!!!");
    return 0;
}