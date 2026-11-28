import java.util.Scanner;
public class Solution {
    int n,cnt=0; boolean[] col,d1,d2;
    void solve(int row){
        if(row==n){cnt++;return;}
        for(int c=0;c<n;c++) if(!col[c]&&!d1[row-c+n]&&!d2[row+c]){
            col[c]=d1[row-c+n]=d2[row+c]=true; solve(row+1); col[c]=d1[row-c+n]=d2[row+c]=false;
        }
    }
    public int totalNQueens(int n){
        this.n=n;col=new boolean[n];d1=new boolean[2*n];d2=new boolean[2*n]; solve(0); return cnt;
    }
    public static void main(String[] args){
        System.out.println(new Solution().totalNQueens(new Scanner(System.in).nextInt()));
    }
}
