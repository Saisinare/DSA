#include<bits/stdc++.h>
using namespace std;

using V = vector<int>;
class Solution{
public:
    int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int K) {

        vector<vector<pair<int,int>>> graph(n);
        //built a graph from edge list 
        for(auto& it:flights){
            int u = it[0];
            int v = it[1];
            int time = it[2];
            graph[u].push_back({v,time});
        }

        priority_queue<V,vector<V>,greater<V>> q;
        vector<vector<int>> costs(n,vector<int>(K+2,1e9));
        //{cost,city,stops}
        q.push({0,src,0});
        while(!q.empty()){
            int city = q.top()[1];
            int cost = q.top()[0];
            int stops = q.top()[2];
            q.pop();
            if(city == dst) return cost;
            if(stops>K) continue;
            for(auto& it:graph[city]){
                int edge = it.first;
                int edgeWt = it.second;
                if(cost+edgeWt < costs[edge][stops+1]){
                    costs[edge][stops+1] = cost+edgeWt;
                    q.push({cost+edgeWt,edge,stops+1});
                }
            }
        }
        return -1;
    }
};

//Timce ccomplexity: O(E log V)
//Space complexity: O(V + V*K)