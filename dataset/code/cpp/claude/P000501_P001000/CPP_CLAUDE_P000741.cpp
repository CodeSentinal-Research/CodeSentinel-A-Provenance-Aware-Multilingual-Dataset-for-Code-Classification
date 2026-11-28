#include <iostream>
#include <vector>
using namespace std;
class Solution{
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    void dfs(vector<vector<int>>& g,int r,int c,int o,int nw){
        if(r<0||r>=(int)g.size()||c<0||c>=(int)g[0].size()||g[r][c]!=o) return;
        g[r][c]=nw;
        for(int d=0;d<4;d++) dfs(g,r+dx[d],c+dy[d],o,nw);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img,int sr,int sc,int color){
        int o=img[sr][sc];
        if(o!=color) dfs(img,sr,sc,o,color);
        return img;
    }
};
int main(){
    int r,c,sr,sc,color;cin>>r>>c;
    vector<vector<int>> img(r,vector<int>(c));
    for(auto& row:img) for(auto& x:row) cin>>x;
    cin>>sr>>sc>>color;
    auto res=Solution().floodFill(img,sr,sc,color);
    for(auto& row:res){for(int i=0;i<(int)row.size();i++) cout<<row[i]<<(i+1<(int)row.size()?" ":"\n");}
}
