//Push the position of rotten oranges in queue 
//Run a while loop till q.empty 
//Now pop elements out one by one but when you pop out insert its neibours who's value is 1  
//and each time increase the minute count by 1 
//return minute count 

//(when to stop) what is the base case ?? 
//their is no neibours who is 1 
class Solution {
public:
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>>& rotten){
        int min = 0;
        while(!rotten.empty()){
            int size = rotten.size();
            //insert the 4D neibours
            for(int k =0;k<size;k++){
                auto front = rotten.front();
                rotten.pop();
                int i = front.first;
                int j = front.second;
                if(i<grid.size()-1 && grid[i+1][j] == 1){
                    grid[i+1][j] = 2;
                    rotten.push({i+1,j});
                }
                if(i>0 && grid[i-1][j] == 1){
                    grid[i-1][j] = 2;
                    rotten.push({i-1,j});
                }
                if(j<grid[0].size()-1 && grid[i][j+1] == 1){
                    grid[i][j+1] = 2;
                    rotten.push({i,j+1});
                }
                if(j>0 && grid[i][j-1] == 1){
                    grid[i][j-1] = 2;
                    rotten.push({i,j-1});
                }   
            }         
            //complete
            if(!rotten.empty()) min++;
        }
        return min;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int m = grid.size();
        int n = grid[0].size();
        bool hasRotten = false;
        bool isEmpty = true;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 2){
                    rotten.push({i,j});
                    hasRotten = true;
                }
                if(grid[i][j] == 1){
                    isEmpty = false;
                }
            }
        }
        if(isEmpty) return 0;
        if(!hasRotten) return -1;
        int min = bfs(grid,rotten);
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return min;

    }
};

//