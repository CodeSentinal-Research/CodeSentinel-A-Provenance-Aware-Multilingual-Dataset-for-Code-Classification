import java.util.*;
public class Solution {
    public void rotate(int[][] A) {
        int n=A.length;
        for(int i=0;i<n/2;i++) for(int j=i;j<n-1-i;j++){
            int t=A[i][j]; A[i][j]=A[n-1-j][i]; A[n-1-j][i]=A[n-1-i][n-1-j]; A[n-1-i][n-1-j]=A[j][n-1-i]; A[j][n-1-i]=t;
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); int[][] A=new int[n][n];
        for(int[] r:A) for(int j=0;j<n;j++) r[j]=sc.nextInt();
        new Solution().rotate(A);
        for(int[] r:A){StringBuilder sb=new StringBuilder();for(int j=0;j<n;j++) sb.append(r[j]).append(j<n-1?" ":"");System.out.println(sb);}
    }
}
