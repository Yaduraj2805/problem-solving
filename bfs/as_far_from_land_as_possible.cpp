class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(n*n==q.size()){
            return -1;
        }
        int len=0;
        while(q.size()){
            
            int k=q.size();
            len++;
            for(int i=0;i<k;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                int dx[]={1,0,0,-1};
                int dy[]={0,1,-1,0};
                for(int j=0;j<4;j++){
                    int x1=dx[j]+x;
                    int y1=dy[j]+y;
                    if(x1>=0&&x1<n&&y1>=0&&y1<n&&grid[x1][y1]==0){
                        grid[x1][y1]=len;
                        q.push({x1,y1});
                        
                    }
                }
            }
            
        }
        return len-1;
    }
};