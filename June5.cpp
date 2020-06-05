class Solution {
   public:
   int n;
   vector <int> v;
   Solution(vector<int>& w) {
      srand(time(NULL));
      n = w[0];
      for(int i = 1; i < w.size(); i++){
         w[i] += w[i - 1];
         n = w[i];
      }
      v = w;
   }
   int pickIndex() {
      return upper_bound(v.begin(), v.end(), rand() % v.back()) - v.begin();
   }
};
