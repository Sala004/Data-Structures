#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> findOrder(int n, vector<vector<int>> &adj){

    int sz = adj.size();
	vector<int> indegree(sz, 0);	// compute indegrees of nodes
	for (int i = 0; i < sz; ++i)
		for (int j : adj[i])
			indegree[j]++;

	priority_queue<int, vector<int>, greater<int> >	ready;	// small to large
	for (int i = 0; i < sz; ++i)
		if (!indegree[i])
			ready.push(i);

	vector<int> ordering;
	while (!ready.empty()) {	// keep picking a ready node
		int i = ready.top();
		ready.pop();
		ordering.push_back(i);

		for (int j : adj[i])	// remove its outgoing edges
			if (--indegree[j] == 0)	// If a neighbor is ready, add it
				ready.push(j);
	}
	if (ordering.size() != adj.size())
		ordering.clear();    //there are cycles

	return ordering;

}
int main(){
    // Example usage
    int n = 9; // Number of nodes
    vector<vector<int>> adj = {
        {5},        // Node 0 points to nodes 1 and 2
        {0},        // Node 1 points to nodes 3 and 4
        {1, 7, 8},  // Node 2 points to node 5
        {2},        // Node 3 points to node 5
        {2},        // Node 4 points to node 5
        {},         // Node 5 has no outgoing edges
        {},         //Node 6 has no outgoing edges
        {5, 6},     //Node 7
        {6}         //Node 8
    };

    vector<int> res = findOrder(n, adj);
    for(int it : res){
        cout << it << " ";
    }
    return 0;
}
