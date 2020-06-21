typedef long long int lli;
lli min(lli a, lli b)
{
   return a <= b ? a : b;
}
lli max(lli a, lli b)
{
   return a <= b ? b : a;
}
class Solution
{
public:
   int calculateMinimumHP(vector<vector<int>>& dp)
   {
      int r = dp.size();
      int c = dp[0].size();
      for(lli j=r-2;j>=0;j--)
         dp[j][c-1] = min(dp[j][c-1], dp[j][c-1]+dp[j+1][c-1]);

      for(lli j = c-2;j>=0;j--)
         dp[r-1][j] =min(dp[r-1][j], dp[r-1][j]+dp[r-1][j+1]);

      for(lli i = r-2;i>=0;i--)
      {
         for(lli j = c-2;j>=0;j--)
            dp[i][j] = min(dp[i][j],max(dp[i][j]+dp[i+1][j],dp[i][j]+dp[i][j+1]));
      }
      if(dp[0][0] <= 0 )
          return abs(dp[0][0])+1;
       
      return 1;
   }
};
