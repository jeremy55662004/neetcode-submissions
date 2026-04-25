class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int preReq = pre[1];

            //preReq -> course
            adj[preReq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for (int ix = 0; ix < numCourses; ix++) {
            if (indegree[ix] == 0) {
                q.push(ix);
            }

        }
        
        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            for (int nextCourse : adj[curr]) {
                indegree[nextCourse]--;

                if (indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        return count == numCourses;
    }
};
