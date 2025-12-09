// User function Template for C++
/*
    Observations: 
        "T|T&F^T" in this array we can partition this problem in subproblems by their operators 
        (T)|(T&F^T)
        (T|T)&(F^T)
        (T|T&F)^(T)
        
        if i is starting point and j is ending point 
        the K should be looping from i+1 -> j-1 increasing 2 each time 
        
        Q. what will the function will return ? -> no. of ways we can get true from equation 
           1) so if their is subproblems x1 & x2 
                The number of ways we can get true will be x1 * x2 
           2) if a | b 
                x1 = true ways (for a)   x3 = true ways  (for b) 
                x2 = false ways          x4 = false ways 
                
                total True ways = x1*x3 + x1*x4 + x2*x3
            3) if a^b 
                x1 = true ways (for a)   x3 = true ways  (for b) 
                x2 = false ways          x4 = false ways
                
                total True ways = x3*x2 + x1*x4 
                 
*/

//brute force : using recursion
/*
class Solution {
  public:
    int solve(string &s,int i ,int j,int isTrue){
        if(i>j) return 0;
        if(i==j){
            if(isTrue == 1) return s[i] == 'T';
            return s[i] == 'F';
        }
        int res = 0 ;
        for(int k = i+1;k<=j-1;k++){
            int LT = solve(s,i,k-1,1);
            int LF = solve(s,i,k-1,0);
            int RT = solve(s,k+1,j,1);
            int RF = solve(s,k+1,j,0);
            
            if(s[k] == '&'){
                if(isTrue == 1) res += (LT * RT);
                else res += (LF * RT) + (LF * RF) + (LT * RF) ;
            }else if(s[k]=='|'){
                if(isTrue == 1) res += ((LT * RT) + (RT * LF) + (LT * RF));
                else res+= (LF * RF);
            }else{
                if(isTrue == 1) res += ((RT * LF) + (LT * RF));
                else  res += (RT*LT)+(LF*RF);
            }
        }
        return res;
    }
    int countWays(string &s) {
        int n = s.size();
        return solve(s,0,n-1,1);
        
    }
};
*/
//better using memoization: 
/*
class Solution {
  public:
    int solve(string &s,int i ,int j,int isTrue,vector<vector<vector<int>>>& dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue == 1) return s[i] == 'T';
            return s[i] == 'F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int res = 0 ;
        for(int k = i+1;k<=j-1;k++){
            int LT = solve(s,i,k-1,1,dp);
            int LF = solve(s,i,k-1,0,dp);
            int RT = solve(s,k+1,j,1,dp);
            int RF = solve(s,k+1,j,0,dp);
            
            if(s[k] == '&'){
                if(isTrue == 1) res += (LT * RT);
                else res += (LF * RT) + (LF * RF) + (LT * RF) ;
            }else if(s[k]=='|'){
                if(isTrue == 1) res += ((LT * RT) + (RT * LF) + (LT * RF));
                else res+= (LF * RF);
            }else{
                if(isTrue == 1) res += ((RT * LF) + (LT * RF));
                else  res += (RT*LT)+(LF*RF);
            }
        }
        return dp[i][j][isTrue] = res;
    }
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(s,0,n-1,1,dp);
    }
};
*/

//optimal : using tabulation 
class Solution {
  public:
    int solve(string &s,int i ,int j,int isTrue,vector<vector<vector<int>>>& dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue == 1) return s[i] == 'T';
            return s[i] == 'F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int res = 0 ;
        for(int k = i+1;k<=j-1;k++){
            int LT = solve(s,i,k-1,1,dp);
            int LF = solve(s,i,k-1,0,dp);
            int RT = solve(s,k+1,j,1,dp);
            int RF = solve(s,k+1,j,0,dp);
            
            if(s[k] == '&'){
                if(isTrue == 1) res += (LT * RT);
                else res += (LF * RT) + (LF * RF) + (LT * RF) ;
            }else if(s[k]=='|'){
                if(isTrue == 1) res += ((LT * RT) + (RT * LF) + (LT * RF));
                else res+= (LF * RF);
            }else{
                if(isTrue == 1) res += ((RT * LF) + (LT * RF));
                else  res += (RT*LT)+(LF*RF);
            }
        }
        return dp[i][j][isTrue] = res;
    }
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for(int i = n-1;i>=0;i--){
            for(int j = 0 ;j <= n-1 ;j++){
                if(i>j){
                    continue;
                }
                for(int isTrue = 0;isTrue<=1;isTrue++){
                    if(i==j){
                        if (isTrue == 1) dp[i][j][1] = (s[i] == 'T');
                        else dp[i][j][0] = (s[i] == 'F');
                        continue;
                    }
                    int res = 0 ;
                    for(int k = i+1;k<=j-1;k+=2){
                        int LT = dp[i][k-1][1];
                        int LF = dp[i][k-1][0];
                        int RT = dp[k+1][j][1];
                        int RF = dp[k+1][j][0];
                        
                        if(s[k] == '&'){
                            if(isTrue == 1) res += (LT * RT);
                            else res += (LF * RT) + (LF * RF) + (LT * RF) ;
                        }else if(s[k]=='|'){
                            if(isTrue == 1) res += ((LT * RT) + (RT * LF) + (LT * RF));
                            else res+= (LF * RF);
                        }else{
                            if(isTrue == 1) res += ((RT * LF) + (LT * RF));
                            else  res += (RT*LT)+(LF*RF);
                        }
                    }
                    dp[i][j][isTrue] = res;
                }

            }
        }
        return dp[0][n-1][1];
    }
};
