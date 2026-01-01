#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        vector<int> topoSort(int V, vector<vector<int>>& edges) {
            // code here
        	vector<int> indegree(V,0);
        	vector<vector<int>> graph(V);
        
        	for(int i=0;i<edges.size();i++){
        		graph[edges[i][0]].push_back(edges[i][1]);
        		indegree[edges[i][1]]++;
        	}
        	queue<int> q;
        	for(int i =0;i<indegree.size();i++){
        		if(indegree[i]==0){
        			q.push(i);
        		}
        	}
        
        	vector<int> ans;
			
        	while(!q.empty()){
        		int front = q.front();
        		q.pop();
        		ans.push_back(front);
        		
        		int size = graph[front].size();
        		for(int i=0;i<size;i++){
        			if(indegree[graph[front][i]] > 0)indegree[graph[front][i]]--;
        			if(indegree[graph[front][i]] == 0) q.push(graph[front][i]);
        		}
    
        	}
        	return ans;
    
        }
    };