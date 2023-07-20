#include<bits/stdc++.h>
using namespace std;

//if augmenting path exists returns true
bool bfs(vector<vector<int>>&residual_graph, int s, int t, vector<int>&parent, int N){
	vector<int>visited(N, 0);
    
	queue<int>q;
	q.push(s);
	visited[s] = 1;
	parent[s] = -1;
    
	while(!q.empty()){
    	int u = q.front();
    	q.pop();
    	for(int v = 0; v < N; v++){
        	if(visited[v] == 0 && residual_graph[u][v] > 0){
            	if(v == t){
                	parent[v] = u;
                	return true;
            	}
           	 
            	q.push(v);
            	visited[v] = 1;
            	parent[v] = u;
        	}
    	}
	}
	return false;
}

int ford_fulkerson(vector<vector<int>>&graph, int source, int sink, int N){
	vector<vector<int>>residual_graph(N, vector<int>(N));
    
	for(int u = 0; u < N; u++){
    	for(int v = 0; v < N; v++){
        	residual_graph[u][v] = graph[u][v];
    	}
	}
    
	vector<int>parent(N);
	int max_flow = 0;
	int path_flow = INT_MAX;
    
	while(bfs(residual_graph, source, sink, parent, N)){
    	int u;
    	for(int v = sink; v != source; v = parent[v]){
        	u = parent[v];
        	path_flow = min(path_flow, residual_graph[u][v]);
    	}
   	 
    	//update the residual graph
    	for(int v = sink; v != source; v = parent[v]){      	//whole path
        	u = parent[v];
        	residual_graph[u][v] -= path_flow;
        	residual_graph[v][u] += path_flow;
    	}
    	max_flow += path_flow;
	}
	return max_flow;
}

int main()
{
	// vector<vector<int>>graph = {
	// 	{0, 16, 13, 0, 0, 0},
	// 	{0, 0, 10, 12, 0, 0},
	// 	{0, 4, 0, 0, 14, 0},
	// 	{0, 0, 9, 0, 0, 20},
	// 	{0, 0, 0, 7, 0, 4},
	// 	{0, 0, 0, 0, 0, 0},
	// };
    
	int N;
	cout << "Enter number of vertices : " ;
	cin >> N;
	vector<vector<int>>graph(N, vector<int>(N, 0));
    
	// for(int i = 0; i < N; i++){
	// 	cout << "Enter all v's for " << i << "th node ";
	// 	for(int j = 0; j < N; j++){
	//     	cin >> graph[i][j];
	// 	}
	// 	cout << endl;
	// }
    
	int total_edges;
	cout << "How many total edges you want to add? " ;
	cout << endl;
	cin >> total_edges;
    
	for(int i = 0; i < total_edges; i++){
    	cout << "Enter edges from source to destination : " ;
    	int u, v;
    	cin >> u >> v;
    	int max_capacity;
    	cout << "Enter max capacity : ";
    	cin >> max_capacity;
   	 
    	graph[u][v]= max_capacity;
	}
    
	cout << "max flow is : " << ford_fulkerson(graph, 0, N-1, N);

	return 0;
}
