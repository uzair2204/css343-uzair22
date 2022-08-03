class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //Check to see if the size of one string is equal to the other's size
        if (s.size() != t.size())
            return false;
        //Creates a vector with 128 elements and fills each element with false.  This will be used as an index 
        //into a map which will store all values for s and t that were found in the comparison above.
        vector<bool> marked(128, false);
        //creates a map which has 128 entries and for every entry in s, maps it to t but sets its value as -1
        vector<int> map(128, -1);
        //Iterating through all of s's characters until there are no more characters left in s or there are 
        //no more characters left in t (whichever comes first).
        for (int i = 0; i < s.size(); i++) {
            if (map[s[i]] != -1 && map[s[i]] != t[i])
                return false;
            else if (map[s[i]] == -1) {
                if (marked[t[i]])
                    return false;
                map[s[i]] = t[i];
                marked[t[i]] = true;
            }
        }
        return true;
    }
};
