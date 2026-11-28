import java.util.*;
public class Solution {
    public long[][] add(long[][] A, long[][] B) {
        int r=A.length,c=A[0].length; long[][] C=new long[r][c];
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) C[i][j]=A[i][j]+B[i][j];
        return C;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in); int r=sc.nextInt(),c=sc.nextInt();
        long[][] A=new long[r][c],B=new long[r][c];
        for(long[] row:A) for(int j=0;j<c;j++) row[j]=sc.nextLong();
        for(long[] row:B) for(int j=0;j<c;j++) row[j]=sc.nextLong();
        long[][] C=new Solution().add(A,B);
        for(long[] row:C){StringBuilder sb=new StringBuilder();for(int j=0;j<c;j++) sb.append(row[j]).append(j<c-1?" ":"");System.out.println(sb);}
    }
}
