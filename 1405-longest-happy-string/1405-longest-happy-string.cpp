class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        string res;
        priority_queue<pair<int, char>>q;
        
        if(a >0) q.push(make_pair(a, 'a'));
        if(b >0) q.push(make_pair(b, 'b'));
        if(c >0) q.push(make_pair(c, 'c'));
        
        while (! q.empty()){
            auto [count, ch] = q.top();
            q.pop();
            int n = res.size();
            
            if(n >= 2 && res[n-1] == ch && res[n-2] == ch){
                if(!q.empty()){
                    auto [nextCount, nextCh] = q.top();
                    q.pop();
                    res += nextCh;
                    if(nextCount -1 >0) q.push({nextCount-1, nextCh});
                    q.push({count, ch});
                }
                else{
                    break;
                }
                
            }
            else{
                res += ch;
                if(count -1 > 0) q.push({count-1, ch});
            }
        }
        return res;
    }
};