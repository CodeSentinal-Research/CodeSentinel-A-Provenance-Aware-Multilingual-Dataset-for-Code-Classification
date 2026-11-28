import java.util.*;
public class Solution {
    public int[][] transpose(int[][] A) {
        int r=A.length,c=A[0].length; int[][] T=new int[c][r];
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) T[j][i]=A[i][j];
        return T;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in); int r=sc.nextInt(),c=sc.nextInt();
        int[][] A=new int[r][c]; for(int[] row:A) for(int j=0;j<c;j++) row[j]=sc.nextInt();
        int[][] T=new Solution().transpose(A);
        for(int[] row:T){StringBuilder sb=new StringBuilder();for(int j=0;j<T[0].length;j++) sb.append(row[j]).append(j<T[0].length-1?" ":"");System.out.println(sb);}
    }
}
