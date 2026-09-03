class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto&x:prerequisites){
            indegree[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto &neighbor:adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0)q.push(neighbor);
            }
        }
        return count==numCourses;
    }
};