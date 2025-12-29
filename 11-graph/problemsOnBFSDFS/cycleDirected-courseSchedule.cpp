// bool isLoopInPath(int curr, vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& recPath){
//   visited[curr] = true;
//   recPath[curr] = true;

//   for(auto& it:graph[curr]){
//     if(!visited[it]){
//       if(isLoopInPath(it,graph,visited,recPath)) return true;
//     }else if(recPath[it]){
//       return true;
//     }
//   }

//   recPath[curr] = false;
//   return false;

// }
// int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
//   vector<bool> visited(n,false);
//   vector<bool> recPath(n,false);
//   vector<vector<int>> graph(n);
  
//   for(auto& it: edges){
//     graph[it.first-1].push_back(it.second-1);
//   }

//   int v = graph.size();
//   for(int i = 0;i<v;i++){
//     if(!visited[i]){

//     if(isLoopInPath(i,graph,visited,recPath)) return 1;
//     }
//   }
//   return 0;

// }


//more optimal (using 2 state visited array)
class Solution {
public:

    bool isLoopInPath(int curr, vector<vector<int>>& graph,vector<int>& visited){
    visited[curr] = 1;

    for(auto& it:graph[curr]){
        if(visited[it] == 0){
        if(isLoopInPath(it,graph,visited)) return true;
        }else if(visited[it]==1){
        return true;
        }
    }

    visited[curr] = 2;
    return false;

    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> visited(n,0);
        vector<vector<int>> graph(n);
        
        for(auto& it: prerequisites){
            graph[it[0]].push_back(it[1]);
        }
        for(int i = 0;i<n;i++){
            if(visited[i] == 0){
                if(isLoopInPath(i,graph,visited)) return false;
            }
        }
        return true;
    }
};