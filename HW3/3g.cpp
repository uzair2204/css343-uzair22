class Solution {
    enum Color { White, Gray, Black };

    void findOrder_helper(vector<vector<int>>& graph, int vertex, vector<Color>& colors, vector<int>& output, bool& possible) {
        //Sets the color to Gray for vertex 1
        colors[vertex] = Gray;
        //Iterate through all of the vertices in our graph and check if that vertex is already set to Gray.
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            //If color of the vertex is gray return from this function without doing anything else.
            if (colors[graph[vertex][i]] == Gray)
            {
                possible = false;
                return;
            }
            //If not, then we set the color to White and continue on with our looping process.
            if (colors[graph[vertex][i]] == White)
            {
                findOrder_helper(graph, graph[vertex][i], colors, output, possible);
                if (!possible)
                    return;
            }
        }
        //After each iteration, we push back onto our output vector an index of where that vertex was 
        //found in relation to its parent (the previous node).
        colors[vertex] = Black;
        output.push_back(vertex);
    }

public:
    //The code attempts to find the order of courses that satisfy a given set of prerequisites.
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Create a vector graph that will be used to store the order of courses.
        vector<vector<int>> graph(numCourses);
      //Loop through each course and creates an entry for it in the graph, with its own index number and value.
        for (int i = 0; i < prerequisites.size(); i++) 
        {
            //Iterate through each prerequisite in the list and create an edge between two courses, if they share a prerequisite number.
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[a].push_back(b);
        }
        vector<int> output;
        vector<Color> colors(numCourses, White);
        bool possible = true;
        for (int vertex = 0; vertex < numCourses; vertex++)
        {
            if (colors[vertex] == White)
            {
                findOrder_helper(graph, vertex, colors, output, possible);
                if (!possible) 
                {
                    output.clear();
                    break;
                }
            }
        }
        return output;
    }
};

