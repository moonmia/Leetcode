class Solution {
public:
    bool checkOrder(string& s1, string& s2, unordered_map<char, int>map)
    {
        int minSize = min(s1.size(), s2.size());
        
        for(int i=0; i<minSize; i++)
        {
            if(s1[i] != s2[i])
            {
                if(map[s1[i]] < map[s2[i]]) return true;
                else if(map[s1[i]] > map[s2[i]]) return false;
            }
        }
        if(s1.size() == minSize) return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char, int>orders;
        
        for(int i=0; i<order.size(); i++)
        {
            orders[order[i]] = i;
        }
        
        for(int i=0; i<words.size()-1; i++)
        {
            if(checkOrder(words[i], words[i+1], orders) != true) return false;
        }
        return true;
    }
};