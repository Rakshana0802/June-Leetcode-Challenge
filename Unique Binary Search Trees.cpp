class Solution
{
public:
   int numTrees(int n) 
   {
      vector <int> dp(n+1);
      dp[0] = 1;
      for(int i =1;i<=n;i++)
      {
         for(int j = 0;j<i;j++)
         {
            dp[i] += (dp[i-1-j] * dp[j]);
         }
      }
      return dp[n];
   }
};
