import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(),m=sc.nextInt();long[][]p=new long[n+1][m+1];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p[i][j]=sc.nextLong()+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
    int q=sc.nextInt();while(q-->0){int r1=sc.nextInt(),c1=sc.nextInt(),r2=sc.nextInt(),c2=sc.nextInt();
        System.out.println(p[r2+1][c2+1]-p[r1][c2+1]-p[r2+1][c1]+p[r1][c1]);}}}
