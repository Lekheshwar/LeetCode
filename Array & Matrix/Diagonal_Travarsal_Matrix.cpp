vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        if(!m)return {};
        int n = mat[0].size();
        int i = 0, j = 0;
        vector<int> res;
        bool up = true;
        while(i < m && j < n){
            res.push_back(mat[i][j]);
            if(up){
                if(i > 0 && j < n - 1){
                    --i;
                    j++;
                }
                else{
                    up = false;
                    if(j == n - 1)
                        ++i;
                    else
                        j++;
                }
            }
            else{
                if(i < m - 1 && j > 0){
                    ++i;
                    --j;
                }
                else{
                    up = true;
                    if(i == m - 1)++j;
                    else i++;
                }
            }
        }
        return res;
    }
