class Solution {

public:
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size();
        
        n = n*n;
        
        int i,j,k;
        vector<int> vis(n+1,0);
        vector<int> sl(n+1);
        
        k=1;
        int flag = 0;
        for(i=b.size()-1;i>=0;i--){
            if(flag==0){
                for(j=0;j<b.size();j++) {
                sl[k] = b[i][j];
                k++;
                }   
                flag = 1;
            }
            else{
                for(j=b.size()-1;j>=0;j--) {
                sl[k] = b[i][j];
                k++;
                }   
                flag = 0;
                
            }
                
        }
        
        
        
        
        return solve(vis,sl,n);
    }
    
    
    int solve(vector<int>& vis, vector<int>& sl, int n){
        queue<int> q;
        
        q.push(1);
        
        int i,j,k,num;
        
        int res = 0;
        
        while(!q.empty()){
            num = q.size();
            for(k=0;k<num;k++){
                
                i = q.front();
                q.pop();
                
                if(i>=n)
                    return res;
                
                
                for(j=i+1;j<=i+6;j++){
                    
                    if(j>n){
                        break;
                    }

                    if(vis[j]==0){
                        if(sl[j]==-1)
                            q.push(j);
                        else 
                            q.push(sl[j]);
                        


                        vis[j]=1;
                    }
                }
            }
            res++;
        }
        
        return -1;
    }
};