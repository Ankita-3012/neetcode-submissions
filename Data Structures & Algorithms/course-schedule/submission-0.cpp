class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        vector<vector<int>> adj(v);
        for(auto& it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<int> indegrees(v);
        for(int i=0; i<v; i++){
            for(auto& it : adj[i]){
                indegrees[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegrees[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto& it : adj[node]){
                indegrees[it]--;
                if(indegrees[it] == 0) q.push(it);
            }
        }

        if(res.size() != v) return false;
        return true;
    }
};
