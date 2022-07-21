class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int w = times[i][2];
            adj[u].push_back(pair<int, int>(v, w));
        }
        vector<int> d;
        for (int i = 0; i < n; i++) {
            d.push_back(INT_MAX);
        }
        d[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push(pair<int, int>(0, k - 1));
        while (!que.empty()) {
            int u = que.top().second;
            que.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                if (d[adj[u][i].first] > d[u] + adj[u][i].second) {
                    que.push(pair<int, int>(d[adj[u][i].first], adj[u][i].first));
                    d[adj[u][i].first] = d[u] + adj[u][i].second;
                }
            }
        }
        int result = d[k - 1];
        for (int i = 0; i < n; i++)
            if (d[i] > result)
                result = d[i];
        if (result == INT_MAX)
            result = -1;
        return result;
    }
};
