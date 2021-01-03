class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1)return 0;
        
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        vector<bool> vis(n,false);
        int jump = 0;
        
        q.push(0);
        vis[0] = true;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int curr = q.front();
                q.pop();
                if(curr == n - 1)return jump;
                
                if(curr - 1 >= 0 && !vis[curr - 1]){
                    q.push(curr - 1);
                    vis[curr - 1] = true;
                }
                
                if(curr + 1 < n && !vis[curr + 1]){
                    q.push(curr + 1);
                    vis[curr + 1] = true; 
                }
                
                for(auto img : mp[arr[curr]]){
                    if(img != curr && !vis[img]){
                        if(img == n - 1)return jump+1;
                        q.push(img);
                        vis[img] = true;
                    }
                }
                 mp[arr[curr]].clear();
            }
            jump++;
        }
        return -1;
    }
};
