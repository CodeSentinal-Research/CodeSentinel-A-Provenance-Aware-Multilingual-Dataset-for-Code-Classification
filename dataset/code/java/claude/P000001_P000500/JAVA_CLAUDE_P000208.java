import java.util.*;
public class Solution {
    public long diagonalSum(int[][] A) {
        int n=A.length; long s=0;
        for(int i=0;i<n;i++){s+=A[i][i];if(i!=n-1-i)s+=A[i][n-1-i];}
        return s;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in); int n=sc.nextInt(); int[][] A=new int[n][n];
        for(int[] r:A) for(int j=0;j<n;j++) r[j]=sc.nextInt();
        System.out.println(new Solution().diagonalSum(A));
    }
}
