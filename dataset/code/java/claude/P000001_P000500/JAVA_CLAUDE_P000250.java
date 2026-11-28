import java.util.*;
public class Solution{
static double det(double[][]A,int n){double[][]M=new double[n][n];for(int i=0;i<n;i++)M[i]=A[i].clone();double d=1;for(int i=0;i<n;i++){int p=i;for(int k=i+1;k<n;k++)if(Math.abs(M[k][i])>Math.abs(M[p][i]))p=k;if(p!=i){double[]t=M[i];M[i]=M[p];M[p]=t;d*=-1;}if(M[i][i]==0)return 0;d*=M[i][i];for(int k=i+1;k<n;k++){double f=M[k][i]/M[i][i];for(int j=i;j<n;j++)M[k][j]-=f*M[i][j];}}return d;}
public static void main(String[] x){Scanner sc=new Scanner(System.in);int n=sc.nextInt();
double[][]A=new double[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[i][j]=sc.nextDouble();
System.out.println(Math.round(det(A,n)));}}
