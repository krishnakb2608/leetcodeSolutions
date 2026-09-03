class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto&x:prerequisites){
            indegree[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto &neighbor:adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0)q.push(neighbor);
            }
        }
        if(topo.size()==numCourses)return topo;
        else return {};
    }
};