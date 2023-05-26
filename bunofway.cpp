int numOfWays(int n, int x)
    {
        int m=pow(n,1.0/x);
        vector<int>dp(n+1,0);
        dp[0]=1;
        
        for(int i=m;i>0;i--)
        {
            vector<int>temp(n+1,0);
            temp[0]=1;
            
            for(int j=0;j<=n;j++)
            {
                int a=0, b=0;
    
                if(j>=pow(i, x))
                a=dp[j-pow(i,x)];
                
                b=dp[j];
                
                temp[j]=(a+b)%MOD;
            }
            dp=temp;
        }
        return dp[n];
    }
