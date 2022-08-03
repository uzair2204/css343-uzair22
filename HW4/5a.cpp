class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> mat(points.size(), vector<int>(points.size(), INT_MAX));
        vector<int> parent(points.size());
        // Key values used to pick minimum weight edge in cut 
        vector<int> key(points.size(), INT_MAX);
        // To represent set of vertices included in MST
        vector<bool> mstSet(points.size(), false);
        int result = 0, min, min_index, v, x, y;
        // create the graph
        for (x = 0; x < points.size(); x++)
            for (y = x+1; y < points.size(); y++)
                    mat[x][y] = mat[y][x] = abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        // Make key 0 so that this vertex is picked as first vertex. 
        key[0] = 0;
        parent[0] = -1;
        for (int i = 0; i < mat.size() - 1; i++) {
            // Pick the minimum key vertex from the set of vertices not yet included in MST 
            min = INT_MAX;
            for (v = 0; v < mat.size(); v++)
                if (!mstSet[v] && key[v] < min)
                    min = key[v], min_index = v;
            // Add the picked vertex to the MST Set 
            mstSet[min_index] = true;
            for (v = 0; v < mat.size(); v++)
                if (mat[min_index][v] && !mstSet[v] && mat[min_index][v] < key[v])
                    parent[v] = min_index, key[v] = mat[min_index][v];
        }
        for (v = 1; v < mat.size(); v++)
            result += mat[v][parent[v]];
        return result;
    }
};
