class Solution {
public:
    //Main function that takes in an input vector of integers and returns the network delay time 
    //for a given number of nodes and number of hops.
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Vector creation
        vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>());
        //For each pair in times, it creates another vector d with INT_MAX as its first element
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int w = times[i][2];
            adj[u].push_back(pair<int, int>(v, w));
        }
        vector<int> d;
        //Iterates through adj[u] where u is the index of the current pair.
        for (int i = 0; i < n; i++) {
            d.push_back(INT_MAX);
        }
        d[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.push(pair<int, int>(0, k - 1));
        //iterates over que until it's empty, at which point it pushes onto que 
        //top's second element (which will be k - 1) and pops off que again.
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
        //Check if d[i] > result before returning result = d[i].
        for (int i = 0; i < n; i++)
            if (d[i] > result)
                result = d[i];
        //If result == INT_MAX, return -1 instead.
        if (result == INT_MAX)
            result = -1;
        return result;
    }
};
