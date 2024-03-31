class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        if(n*m==1&&grid[0][0]==0){
            return 0;
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-1;
                }
                if(grid[i][j]==0) count++;
            }
        }
        if(n*m==q.size()||n*m==count){
            return 0;
        }
        int len=0;
        while(q.size()){
            int k=q.size();
            
            for(int j=0;j<k;j++){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[]={0,1,-1,0};
            int dy[]={1,0,0,-1};
            for(int i=0;i<4;i++){
                int x1=dx[i]+x;
                int y1=dy[i]+y;
                if(x1>=0&&x1<n&&y1>=0&&y1<m&&grid[x1][y1]==1){
                    grid[x1][y1]=-1;
                    q.push({x1,y1});
                }

            }
            
            }
            len++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return len-1;
    }
};