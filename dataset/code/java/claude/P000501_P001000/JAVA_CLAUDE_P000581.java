import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();int[]A=new int[n];for(int i=0;i<n;i++)A[i]=sc.nextInt();
    int m=sc.nextInt();int[]B=new int[m];for(int i=0;i<m;i++)B[i]=sc.nextInt();
    int i=0,j=0;StringBuilder sb=new StringBuilder();
    while(i<n&&j<m){if(A[i]<=B[j])sb.append(A[i++]);else sb.append(B[j++]);sb.append(' ');}
    while(i<n){sb.append(A[i++]);sb.append(' ');}while(j<m){sb.append(B[j++]);sb.append(' ');}
    System.out.println(sb.toString().trim());}}
