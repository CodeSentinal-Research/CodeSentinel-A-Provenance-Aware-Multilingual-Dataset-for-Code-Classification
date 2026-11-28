import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();int[]a=new int[n*n];
for(int i=0;i<n*n;i++)a[i]=sc.nextInt();Arrays.sort(a);
StringJoiner sj=new StringJoiner(" ");for(int v:a)sj.add(String.valueOf(v));System.out.println(sj);}}
