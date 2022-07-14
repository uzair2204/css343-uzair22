class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //Min Heap Construction
        vector<vector<int>> v;
        for (int s = points.size() / 2 - 1; s >= 0; s--) {
            int i = s;
            while (true) {
                int min = i, l = 2 * i + 1;
                if (l < points.size()) {
                    int r = l + 1;
                    if (dist(points[min]) > dist(points[l]))
                        min = l;
                    if (r < points.size() && dist(points[min]) > dist(points[r]))
                        min = r;
                }
                if (i == min)
                    break;
                swap(points[min], points[i]);
                i = min;
            }
        }
        
        //Removing shortest points from the heap 
        while (points.size() > 0 && k > 0) {
            vector<int> minPoint = points[0];
            points[0] = points[points.size() - 1];
            points.pop_back();
            int i = 0;
            while (true) {
                int min = i, l = 2 * i + 1;
                if (l < points.size()) {
                    int r = l + 1;
                    if (dist(points[min]) > dist(points[l]))
                        min = l;
                    if (r < points.size() && dist(points[min]) > dist(points[r]))
                        min = r;
                }
                if (i == min)
                    break;
                swap(points[i], points[min]);
                i = min;
            }
            v.push_back(minPoint);
            k--;
        }
        return v;
    }
    
    //Compare distance of points passed as argument
    double dist(vector<int>& v) {
        return sqrt(v[0] * v[0] + v[1] * v[1]);
    }
    
};
