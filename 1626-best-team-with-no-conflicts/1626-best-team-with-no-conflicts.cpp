class Solution {
public:
    int dp[100005];
    
    int lis(int i,vector<int>& ans)
    {
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        int res=ans[i];
        for(int j=0;j<i;j++)
        {
            if(ans[i]>=ans[j])
            {
                res=max(res,lis(j,ans)+ans[i]);
            }
        }
        
        return dp[i]=res;
    }
    
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        memset(dp,-1,sizeof(dp));
        
        vector<pair<int,int>> v;
        int n=scores.size();
        
        for(int i=0;i<n;i++)
        {
            v.push_back({ages[i],scores[i]});
        }
        
        sort(v.begin(),v.end());
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(v[i].second);
            //cout<<v[i].second<<endl;
        }
        
        int an=0;
        
        for(int i=0;i<n;i++)
        {
            an=max(an,lis(i,ans));
        }
        
        return an;
        
    }
};