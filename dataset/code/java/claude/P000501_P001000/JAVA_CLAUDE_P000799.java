import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt(),m=sc.nextInt();long[][]g=new long[n][m],p=new long[n+1][m+1];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)g[i][j]=sc.nextLong();
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)p[i][j]=g[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
    for(int i=1;i<=n;i++){StringJoiner sj=new StringJoiner(" ");for(int j=1;j<=m;j++)sj.add(String.valueOf(p[i][j]));System.out.println(sj);}}}
