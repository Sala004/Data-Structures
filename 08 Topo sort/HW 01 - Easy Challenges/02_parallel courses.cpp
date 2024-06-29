#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int parallelCourses(int n, vector<vector<int>> &adj){

    int sz = adj.size();
	vector<int> indegree(sz, 0);	// compute indegrees of nodes
	for (int i = 0; i < sz; ++i)
		for (int j : adj[i])
			indegree[j]++;

	queue<int>	ready;	
	for (int i = 0; i < sz; ++i)
		if (!indegree[i])
			ready.push(i);

	vector<int> ordering;
    int found_nodes = 0;
    int nSmester = 0;
	while (!ready.empty()) {	// keep picking a ready node
        int level_size = ready.size();
        while(level_size--){
            int curr = ready.front();
            ready.pop();
            found_nodes++;

            for (int j : adj[curr])	// remove its outgoing edges
			if (--indegree[j] == 0)	// If a neighbor is ready, add it
				ready.push(j);
        }
        nSmester++;
    }
    
	if(found_nodes != adj.size()){
        return -1;
    }
    return nSmester;

}

int main() {
    int n = 3; // Number of courses
    vector<vector<int>> adj = {
        {},        // Course 0 prerequisites: course 1
        {},        // Course 1 prerequisites: course 2
        {0, 1}     // Course 2 prerequisites: course 5   
    };

    int minSemesters = parallelCourses(n, adj);
    if (minSemesters == -1) {
        cout << "Impossible to complete all courses due to cycle." << endl;
    } else {
        cout << "Minimum semesters needed to complete all courses: " << minSemesters << endl;
    }

    return 0;
}