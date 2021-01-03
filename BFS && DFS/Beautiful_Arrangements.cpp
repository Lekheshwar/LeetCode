int cnt = 0;
    void rec(vector<bool>& ch, int idx, int n){
        if(idx > n){
            cnt++;
            return;
        };
        
        
        for(int i = 1; i <= n; i++){
            if((idx % i == 0 || i % idx == 0) && !ch[i]){
                ch[i] = true;
                rec(ch, idx + 1, n);
                ch[i] = false;
            }
        }
        
    }
    
    
    int countArrangement(int n) {
        vector<bool> ch(n+1, false);
        rec(ch,1,n);
        return cnt;
    }
