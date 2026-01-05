#include<bits/stdc++.h> 
using namespace std;

using P = pair<int,int>;

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        //define priority queue
        //{distance,node}
        priority_queue<P,vector<P>,greater<P>> q;
        //create a distance array with V size and all of the nodes distance as maxi 
        vector<int> dis(V,1e9);
        dis[S] = 0;
        q.push({0,S});
        
        while(!q.empty()){
            int dist = q.top().first;
            int ele = q.top().second;
            q.pop();
            if(dist>dis[ele]) continue;
            for(auto& it:adj[ele]){
                int edge = it[0];
                int edgeWt = it[1];
                
                if(dist + edgeWt < dis[edge]){
                    dis[edge] = dist + edgeWt;
                    q.push({dis[edge],edge});
                }
            }

        }

        return dis;

    }
};

/*
Time Complexity: O((V+E)*logV) (where V and E represent the number of nodes and edges of the graph)

Each node is processed once in the priority queue and deletion and insertion operation takes O(logV) time making it overall O(V*logV) in the worst case.
For each vertex, all its edges are relaxed. This operation involves updating the priority queue, which takes O(logV) making it overall O(E*logV) for E edges in the worst case.
Space Complexity: O(V)

The priority queue will store distances to all nodes in worst case leading to O(V) space.
The distance array takes O(V) space.
*/