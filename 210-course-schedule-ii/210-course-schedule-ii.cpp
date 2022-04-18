class Solution {
private:
    vector<vector<int>>graph;
    vector<int>visited;
    bool valid = true;
    vector<int>result;
public:
    void dfs(int n){
        visited[n] = 1;
        for(int m : graph[n]){
            if(visited[m] == 0){
                dfs(m);
                if(!valid){
                    return;
                }
            }
            else if(visited[m] == 1){
                valid = false;
                return;
            }
        }
        
        visited[n] =2;
        result.push_back(n);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        visited.resize(numCourses);
        for(auto& info : prerequisites){
            graph[info[1]].push_back(info[0]);
        }
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        if(!valid){
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
};