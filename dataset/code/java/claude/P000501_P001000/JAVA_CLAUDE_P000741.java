import java.util.*;
public class Solution {
    int[] dx={0,0,1,-1},dy={1,-1,0,0};
    void dfs(int[][] g,int r,int c,int o,int nw){
        if(r<0||r>=g.length||c<0||c>=g[0].length||g[r][c]!=o)return;
        g[r][c]=nw; for(int d=0;d<4;d++) dfs(g,r+dx[d],c+dy[d],o,nw);
    }
    public int[][] floodFill(int[][] img,int sr,int sc,int color){
        if(img[sr][sc]!=color) dfs(img,sr,sc,img[sr][sc],color); return img;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in); int r=sc.nextInt(),c=sc.nextInt();
        int[][] img=new int[r][c]; for(int[] row:img) for(int j=0;j<c;j++) row[j]=sc.nextInt();
        int[][] res=new Solution().floodFill(img,sc.nextInt(),sc.nextInt(),sc.nextInt());
        for(int[] row:res){StringBuilder sb=new StringBuilder();for(int j=0;j<c;j++) sb.append(row[j]).append(j<c-1?" ":"");System.out.println(sb);}
    }
}
