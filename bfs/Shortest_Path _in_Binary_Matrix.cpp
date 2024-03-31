class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]||grid[n-1][n-1]){
            return -1;
        }
        grid[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int len=0;
        while(q.size()){
            len++;
            int n1=q.size();
            while(n1--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1&&y==n-1){
                    return len;
                }
                int dx[]={1,-1,0,0,1,1,-1,-1};
                int dy[]={0,0,1,-1,1,-1,1,-1};
                for(int i=0;i<8;i++){
                    int x1=x+dx[i];
                    int y1=y+dy[i];
                    if(x1>=0&&x1<n&&y1>=0&&y1<n&&grid[x1][y1]==0){
                        grid[x1][y1]=1;
                        q.push({x1,y1});
                    }
                }
            }
        }
        return -1;

    }
};