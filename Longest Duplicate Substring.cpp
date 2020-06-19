typedef long long int lli;
class Solution
{
   public:
   int m = 1e9 + 7;
   int add(lli a, lli b)
   {
      return ((a % m) + (b % m)) % m;
   }
   int sub(lli a, lli b)
   {
      return ((a % m) - (b % m) + m) % m;
   }
   int mul(lli a, lli b)
   {
      return ((a % m) * (b % m)) % m;
   }
   vector<int> power;
   string ok(int x, string s)
   {
      if (x == 0)
      return "";
      unordered_map<int, vector<int> > hash;
      lli current = 0;
      for (int i = 0; i < x; i++)
      {
         current = add(mul(current, 26), s[i] - 'a');
      }
      hash[current] = vector<int>(1, 0);
      int n = s.size();
      for (int i = x; i < n; i++)
      {
         current = sub(current, mul(power[x - 1], s[i - x] - 'a'));
         current = add(mul(current, 26), s[i] - 'a');
         if (hash.count(current))
         {
            for (auto& it : hash[current]) 
            {
               if (s.substr(it, x) == s.substr(i - x + 1, x)) 
               {
                  return s.substr(it, x);
               }
            }
         } 
         else 
         {
            hash[current].push_back(i - x + 1);
         }
      }
      return "";
   }
   string longestDupSubstring(string S)
   {
      string ret = "";
      int n = S.size();
      power = vector<int>(n, 1);
      for (int i = 1; i < n; i++)
      {
         power[i] = mul(power[i - 1], 26);
      }
      int low = 0;
      int high = n - 1;
      while (low <= high) 
      {
         int mid = low + (high - low) / 2;
         string temp = ok(mid, S);
         if (temp.size() == 0) 
         {
            high = mid - 1;
         } 
         else 
         {
            if (temp.size() > ret.size())
            ret = temp;
            low = mid + 1;
         }
      }
      return ret;
   }
};
