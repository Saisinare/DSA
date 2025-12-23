class Solution {
public:

    void bfs(vector<vector<int>>& grid,queue<pair<int,int>>& rotten,int startColor,int newColor){
        while(!rotten.empty()){
            int size = rotten.size();
            //insert the 4D neibours
            for(int k =0;k<size;k++){
                auto front = rotten.front();
                rotten.pop();
                int i = front.first;
                int j = front.second;
                if(i<grid.size()-1 && grid[i+1][j] == startColor){
                    grid[i+1][j] = newColor;
                    rotten.push({i+1,j});
                }
                if(i>0 && grid[i-1][j] == startColor){
                    grid[i-1][j] = newColor;
                    rotten.push({i-1,j});
                }
                if(j<grid[0].size()-1 && grid[i][j+1] == startColor){
                    grid[i][j+1] = newColor;
                    rotten.push({i,j+1});
                }
                if(j>0 && grid[i][j-1] == startColor){
                    grid[i][j-1] = newColor;
                    rotten.push({i,j-1});
                }  
            }         
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> rotten;
        rotten.push({sr,sc});
        int startColor = image[sr][sc];
        if (image[sr][sc] == color) return image;
        image[sr][sc] = color;
        bfs(image,rotten,startColor,color);
        return image;
    }
};