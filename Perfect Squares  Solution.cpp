#define INF 1e9
class Solution
{
   public:
   int numSquares(int n)
   {
      vector < int > dp(n+1,INF);
      dp[0] = 0;
      for(int i =1;i*i<=n;i++)
      {
         int x = i*i;
         for(int j = x;j<=n;j++)
         {
            dp[j] = min(dp[j],1+dp[j-x]);
         }
      }
      return dp[n];
   }
};
