import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int r=sc.nextInt(),c=sc.nextInt();
        int[][] A=new int[r][c];
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) A[i][j]=sc.nextInt();
        long best=Long.MIN_VALUE;
        for(int i=0;i+2<r;i++) for(int j=0;j+2<c;j++){
            long s=A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+A[i+2][j]+A[i+2][j+1]+A[i+2][j+2];
            best=Math.max(best,s);
        }
        System.out.println(best);
    }
}
