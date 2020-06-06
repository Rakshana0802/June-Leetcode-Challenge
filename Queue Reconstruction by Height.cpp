bool sorting(vector<int>& a, vector<int>& b)
    {
        if (a[0]<b[0]){ return true;}
        else if(a[0]==b[0] && a[1]>b[1]){return true;}
        else{return false;}
    }

class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) 
    {
        sort(p.begin(), p.end(), sorting);
        vector < vector <int> > ans;
        for(int i = p.size()-1; i>=0; i--)
        {
            ans.insert(ans.begin() + p[i][1], p[i]);
        }
      return ans;
    }
};
