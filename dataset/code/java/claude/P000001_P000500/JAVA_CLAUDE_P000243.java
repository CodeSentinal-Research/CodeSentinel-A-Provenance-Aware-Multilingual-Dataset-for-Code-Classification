import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int r=sc.nextInt(),c=sc.nextInt(),t=sc.nextInt();
int[][]A=new int[r][c];for(int i=0;i<r;i++)for(int j=0;j<c;j++)A[i][j]=sc.nextInt();
int i=0,j=c-1;
while(i<r&&j>=0){if(A[i][j]==t){System.out.println("Found");return;}else if(A[i][j]>t)j--;else i++;}
System.out.println("Not Found");}}
