//thinking : 
/*
    1. the graph is bipertite if their is even (count nodes) loop or no loop in the graph 
    2. to find out we can use the DFS or BFS but in this approach we are using only DFS 
    3. this question mentioned that we have to divide this into 2 sets so that every node from set1 has exactly 1 node int set2
    4. so we have to use two colors 

    Solution: 
    Maintain a visited array where each node is mark as the -1 means no visited and we have not allocated color for it 
    start with the first node and perform dfs until we found the neighbore element which has the same color as the current one 
    if we found it return true 
    it not then false 
    at last return false if we got false from any of the decisions   

*/
class Solution {
public:
    bool traverse(vector<vector<int>>& graph,vector<int>& colors,int node,int color){
        colors[node] = color;
        for(int it: graph[node]){
            if(colors[it] == -1){
                if(color == 1){
                    if(!traverse(graph,colors,it,0)) return false;
                }
                else{
                    if (!traverse(graph,colors,it,1)) return false;
                }
            }else{
                if(color==colors[it]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> colors(V,-1);

        //we are calling this DFS on unvisited node as their is possibility that the graph is formed by connected components  
        for(int i =0;i<V;i++){
            if(colors[i]==-1 && !graph[i].empty()){
                if(!traverse(graph,colors,i,0)) return false;
            }
        }
        return true;
    }
};


class Solution{
public:
//basic idea is if we can divide our graph into two parts 
//and every node in the adj connects set a to the set b means 2 adj nodes should be int he different sets 
//lets consider 2 different sets 0 and 1 
//if we can divide each node in the edges in 0 and 1 then the graph is bipertite 
//their are two conditions either we have loop in graph or not have any loop 
//if their is the loop then graph is only bipertite if the number of nodes in loop is even 
    bool bfs(int start,vector<int> adj[],vector<int>& color){
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int ele:adj[node]){
                if(color[ele] == -1){
                    q.push(ele);
                    if(color[node] == 0){
                        color[ele] = 1;
                    }else if(color[node] == 1){
                        color[ele] = 0;
                    }
                }else{
                    if(color[ele] == color[node]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<int> adj[])  {
        
        vector<int> color(V,-1);
        for(int i =0;i<V;i++){
            if(color[i]==-1){
                if(!bfs(i,adj,color)) return false;
            }
        }
        return true;
    }
};
