class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list
        vector<int> adj[numCourses];

        // Indegree array
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree
        for(auto &it : prerequisites) {

            int u = it[1]; // prerequisite course
            int v = it[0]; // course dependent on u

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        // Push all nodes having indegree 0
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // Store topological ordering
        vector<int> topo;

        // Kahn's Algorithm (BFS)
        while(!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            // Traverse neighbours
            for(auto it : adj[node]) {

                indegree[it]--;

                // If indegree becomes 0,
                // push into queue
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If all courses are processed,
        // no cycle exists
        if(topo.size() == numCourses)
            return true;

        return false;
    }
};