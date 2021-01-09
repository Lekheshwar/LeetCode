class Solution {
public:
    bool isValid(string s1, string s2){
        int cnt = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i])cnt++;
            if(cnt == 2)return false;
        }
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, vector<string>> adj;
        int n = wordList.size();
        unordered_map<string, bool> vis;
        for(auto x : wordList){
            if(isValid(beginWord, x)){
                adj[beginWord].push_back(x);
                adj[x].push_back(beginWord);
            }
        }
        for(int i = 0; i < n; i++){
            vis[wordList[i]] = false;
            for(int j = i + 1; j < n; j++){
                if(isValid(wordList[i], wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        if(adj.find(endWord) == adj.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int cnt = 1;
        vis[beginWord] = true;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                string curr = q.front();
                q.pop();
                for(auto neigh : adj[curr]){
                    if(vis[neigh])continue;
                    if(neigh == endWord)return cnt + 1;
                    q.push(neigh);
                    vis[neigh] = true;
                }
            }
            cnt++;
        }
        return 0;
    }
};
