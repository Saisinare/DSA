#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
        vector<int> topoSort(int V, vector<vector<int>>& edges,vector<bool>& present) {
            // code here
        	vector<int> indegree(V,0);
        	vector<vector<int>> graph(V);
        
        	for(int i=0;i<edges.size();i++){
        		graph[edges[i][0]].push_back(edges[i][1]);
        		indegree[edges[i][1]]++;
        	}
        	queue<int> q;
        	for(int i =0;i<indegree.size();i++){
        		if(present[i] && indegree[i]==0){
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
        
        string findOrder(vector<string> &words) {
            vector<int> adj;
            vector<vector<int>> edges;
            vector<bool> present(26, false);

            
            for (auto &w : words)
                for (char c : w)
                    present[c - 'a'] = true;
                
            for(int i = 0;i<words.size()-1;i++){
                string first = words[i];
                string second = words[i+1];
                int size = min(first.size(),second.size());
                bool found = false;
                for(int ptr = 0 ;ptr<size;ptr++){
                    if(first[ptr]!=second[ptr]){
                        edges.push_back({first[ptr]-'a',second[ptr]-'a'});
                        found = true;
                        break;
                    }
                }
                if(!found && first.size() > second.size()) return "";
            }

            
            vector<int> topo = topoSort(26, edges, present);
            string ans = "";
                        
            int cnt = 0;
            for (bool x : present) if (x) cnt++;
            if (topo.size() != cnt) return "";
            
            for(int x : topo)
                ans.push_back(char('a' + x));
            
            return ans;
        }
};