#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
	vector<int> adj[9]; // conversion of edges which is vector of vector into adj list
	for (auto it : edges) {
		adj[it[0]].push_back(it[1]);
		adj[it[1]].push_back(it[0]);
	}
	int dist[9];//instead of declaring visited array i have declared dist array for the number of nodes we have
	for (int i = 0; i < 9; i++) dist[i] = 1e9; // each value is the maximum of associated
	dist[src] = 0;// initial value is of src vertex is zero distance
	queue<int> q;// instead of using dfs we have bfs traversal for the distance calculation
	q.push(src);// we have put the src vertex into the queue 
	while (!q.empty()) {
		int x = q.front();// then dequeue the top element.
		q.pop();// then pop the vertex from the queue
		for (auto it : adj[x]) { // we have taken out all the neighbour node of the popped vertex and calculated the distance 
			if (dist[x] + 1 < dist[it]) { // if the distance of the node is less than the infinity we have assigned it to the distance vector array
				dist[it] = dist[x] + 1; 
				q.push(it); //pushed the neighbour of the popped vertex
			}
		}
	}
	vector<int> ans(N, -1);
	for (int i = 0; i < N; i++) {
		if (dist[i] != 1e9) {  // if any of the value in the distance array is infinity means that node is not reachable
			ans[i] = dist[i];
		}
	}
	return ans;

}
int main() {
	int n = 9;
	int m = 10;
	vector<vector<int>> edges = {
		{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6},
		{1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}
	};
	int src=0;
	for (auto it : shortestPath(edges, 9, 10, 0))
		cout << it << " ";

	return 0;
}