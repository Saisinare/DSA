using P = pair<int,int>;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //convert this into normal graph adjacency list 
        vector<vector<pair<int,int>>> graph(n+1);

        for(auto& it:times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u].push_back({v,wt});
        }
        
        vector<int> distance(n+1,1e9);
        priority_queue<P,vector<P>,greater<P>> q;

        q.push({k,0});
        distance[k] = 0;

        while(!q.empty()){
            int node = q.top().first;
            int nodeWt = q.top().second;
            q.pop();
            if(nodeWt > distance[node]) continue;
            for(auto& it:graph[node]){
                int wt = it.second;
                int edge = it.first;
                if(nodeWt+wt < distance[edge]){
                    distance[edge] =nodeWt+wt;
                    q.push({edge,distance[edge]});
                }
            }
        }

        int maxi = 0;
        for(int i =1;i<distance.size();i++){
            maxi = max(maxi,distance[i]);
            if(distance[i]==1e9) return -1;
        }
        return maxi;
    }
};

//Time Complexity: (E log v) where E is the number of edges and V is the number of vertices
//Space Complexity: O(E) for adjacency list + O(V) for distance array + O(V) for priority queue = O(E + V)