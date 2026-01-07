using P = pair<long long,long long>;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //convert it into normal adjacency list 
        if(n==0) return 0;
        vector<vector<pair<int,int>>> graph(n);

        for(auto& it:roads){
            int u = it[0];
            int v = it[1];
            int time = it[2];
            graph[u].push_back({v,time});
            graph[v].push_back({u,time});
        }

        int count = 0 ;
        //{time,node}
        priority_queue<P,vector<P>,greater<P>> q;
        //{time,count}
        vector<pair<long long,long long>> time(n, {LLONG_MAX, 0});
        
        time[0] = {0,1};
        q.push({0,0});
        int MOD = 1e9 + 7;

        while(!q.empty()){
            int node = q.top().second;
            long long nodeTime = q.top().first;
            q.pop();
            if(nodeTime>time[node].first) continue;

            for(auto& it:graph[node]){
                int nextNode = it.first;
                int nextTime = it.second;

                long long newTime = ((long long)nodeTime + nextTime);

                if(newTime<time[nextNode].first){
                    time[nextNode].first = newTime;
                    time[nextNode].second = time[node].second;
                    q.push({time[nextNode].first,nextNode});
                }else if(newTime == time[nextNode].first){
                    time[nextNode].second = (time[node].second + time[nextNode].second) % MOD;
                }
            }
        }
        return time[n-1].second;
    }
};

//TC: E × log V
//SC: Adjacency list  → O(V + E)
// Distance array  → O(V)
// Priority queue  → O(E)
//O(V + E)


/*
Treated an undirected graph as directed (missed reverse edge).

Didn’t initialize source node (time[0] = {0,1} missing).

Pushed wrong node in priority queue ({0,1} instead of {0,0}).

Used pair<int,int> for PQ when distance needs long long.

Stored PQ distance into an int variable (downcasting overflow).

Calculated newTime using int arithmetic (overflow before cast).

Casted after addition, not before (overflow already happened).

Used 1e9 instead of LLONG_MAX for initial distances.

Stored node index as path count (time[nextNode].second = nextNode).

Incremented path count on PQ pop (wrong logic).

Updated distance field instead of ways field in equal-path case.

Forgot that ways come from parent paths, not from node itself.

Didn’t reset old path counts when a shorter path was found.

Mixed meanings of {time, count} and {time, node} in pairs.

Assumed code was correct for small n (overflow shows only at n = 200).
*/

//Time Complexity: 