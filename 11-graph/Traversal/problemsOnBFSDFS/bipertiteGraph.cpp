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