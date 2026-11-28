import java.util.*;
public class Solution {
    public long[][] multiply(long[][] A, long[][] B) {
        int r1=A.length,c1=A[0].length,c2=B[0].length;
        long[][] C=new long[r1][c2];
        for(int i=0;i<r1;i++) for(int j=0;j<c2;j++) for(int k=0;k<c1;k++) C[i][j]+=A[i][k]*B[k][j];
        return C;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int r1=sc.nextInt(),c1=sc.nextInt(),r2=sc.nextInt(),c2=sc.nextInt();
        long[][] A=new long[r1][c1],B=new long[r2][c2];
        for(long[] r:A) for(int j=0;j<c1;j++) r[j]=sc.nextLong();
        for(long[] r:B) for(int j=0;j<c2;j++) r[j]=sc.nextLong();
        long[][] C=new Solution().multiply(A,B);
        for(long[] r:C){StringBuilder sb=new StringBuilder();for(int j=0;j<c2;j++) sb.append(r[j]).append(j<c2-1?" ":"");System.out.println(sb);}
    }
}
