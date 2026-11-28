import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
double[][]A=new double[n][n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[i][j]=sc.nextDouble();
boolean ok=true;
for(int i=0;i<n&&ok;i++)for(int j=0;j<n&&ok;j++){double d=0;for(int k=0;k<n;k++)d+=A[i][k]*A[j][k];double e=i==j?1:0;if(Math.abs(d-e)>1e-6)ok=false;}
System.out.println(ok?"Yes":"No");}}
