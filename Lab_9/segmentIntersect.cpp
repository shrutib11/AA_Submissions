#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x, y;
}P;

bool OnSegment(struct Point p1, struct Point p2, struct Point p3){
	if((min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x)) && (min(p1.y, p2.y) <= p3.y <= max(p1.y, p2.y))) return true;
	else return false;
}

int direction(struct Point p1, struct Point p2, struct Point p3){
	struct Point temp1;
	temp1.x = p3.x - p1.x;
	temp1.y = p3.y - p1.y;
    
	struct Point temp2;
	temp2.x = p2.x - p1.x;
	temp2.y = p2.y - p1.y;
    
	int ans = (temp1.x * temp2.y) - (temp1.y * temp2.x);
	return ans;
}

bool segmentIntersect(struct Point P1, struct Point P2, struct Point P3, struct Point P4){
	int d1 = direction(P3, P4, P1);
	cout << d1 << endl;
	int d2 = direction(P3, P4, P2);
	cout << d2 << endl;
	int d3 = direction(P1, P2, P3);
	cout << d3 << endl;
	int d4 = direction(P1, P2, P4);
	cout << d4 << endl;
	
	if((d1 * d2 < 0) && (d3 * d4 < 0)) return true;
	else if(d1 == 0 && OnSegment(P3, P4, P1)) return true;
	else if(d2 == 0 && OnSegment(P3, P4, P2)) return true;
	else if(d3 == 0 && OnSegment(P1, P2, P3)) return true;
	else if(d4 == 0 && OnSegment(P1, P2, P4)) return true;
	else return false;
}

int main(){
	struct Point P[4];
	for(int i = 0; i < 4; i++){
    	cout << "Enter " << (i+1) << "th point" << endl;
    	cin >> P[i].x;
    	cin >> P[i].y;
	}
	cout << segmentIntersect(P[0], P[1], P[2], P[3]);
	return 0;
}
