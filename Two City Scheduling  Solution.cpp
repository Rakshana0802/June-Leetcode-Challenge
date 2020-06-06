class Solution
{
    struct compare
    {
        bool operator()(vector<int>& p1, vector<int>& p2)
        {
            return (p1[0] - p1[1]) < (p2[0] - p2[1]);
        }
    };

   public:
    int twoCitySchedCost(vector<vector<int>>& costs)
    {
        int ans = 0;
        sort(costs.begin(), costs.end(), compare());

        for (int i = 0; i < costs.size() / 2; i++)
        {
            ans += costs[i][0];
        }

        for (int i = costs.size() / 2; i < costs.size(); i++)
        {
            ans += costs[i][1];
        }

        return ans;
    }
};
