class Solution {
public:
    int findParent(int child,vector<int>&parent){
        if(parent[child]==child)return child;
        return parent[child]=findParent(parent[child],parent);
    }
    void unionFind(vector<int>&parent,vector<int>&rank,int node1,int node2){
        int parNode1=findParent(node1,parent);
        int parNode2=findParent(node2,parent);
        if(parNode1==parNode2)return;
        else if(rank[parNode1]>rank[parNode2]){
            parent[parNode2]=parNode1;
        }else if(rank[parNode1]<rank[parNode2]){
            parent[parNode1]=parNode2;
        }else{
            parent[parNode1]=parNode2;
            rank[parNode2]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>rank(n+1,0);
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        for(auto x:edges){
            int par_u=findParent(x[0],parent);
            int par_v=findParent(x[1],parent);
            if(par_u==par_v)return {x[0],x[1]};
            else{
                unionFind(parent,rank,x[0],x[1]);
            }
        }
        return {};

    }
};