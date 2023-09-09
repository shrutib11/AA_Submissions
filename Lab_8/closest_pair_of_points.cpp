#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
}P;

void ClosestPairOfPoints(struct Point p[3]){
    int index_i, index_j;
    int dmin = INT_MAX;
    for(int i = 0; i < 2; i++){
        for(int j = i + 1; j < 3; j++){
            int d = pow((p[i].x - p[j].x), 2) + pow((p[i].y - p[j].y), 2);
            if(d < dmin){
                dmin = d;
                index_i = i+1;
                index_j = j+1;
            }
        }
    }
    cout << "Closest Point is : " << index_i << " " << index_j << endl;
    cout << "Distance between these two are : " << dmin << endl;
}

int main(){
    struct Point P[3];
    for(int i = 0; i < 3; i++){
        cout << "Enter " << (i+1) << "th point" << endl;
        cin >> P[i].x;
        cin >> P[i].y;
    }

    ClosestPairOfPoints(P);
    return 0;
}