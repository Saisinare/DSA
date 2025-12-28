bool isLoopInPath(int curr, vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& recPath){
  visited[curr] = true;
  recPath[curr] = true;

  for(auto& it:graph[curr]){
    if(!visited[it]){
      if(isLoopInPath(it,graph,visited,recPath)) return true;
    }else if(recPath[it]){
      return true;
    }
  }

  recPath[curr] = false;
  return false;

}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<bool> visited(n,false);
  vector<bool> recPath(n,false);
  vector<vector<int>> graph(n);
  
  for(auto& it: edges){
    graph[it.first-1].push_back(it.second-1);
  }

  int v = graph.size();
  for(int i = 0;i<v;i++){
    if(!visited[i]){

    if(isLoopInPath(i,graph,visited,recPath)) return 1;
    }
  }
  return 0;

}