import java.util.*;
public class Solution{
public static void main(String[] x){
Scanner sc=new Scanner(System.in);int n=sc.nextInt();
int[]a=new int[n],d=new int[n];for(int i=0;i<n;i++)a[i]=sc.nextInt();for(int i=0;i<n;i++)d[i]=sc.nextInt();
Arrays.sort(a);Arrays.sort(d);int p=1,res=1,i=1,j=0;
while(i<n&&j<n){if(a[i]<=d[j]){p++;i++;}else{p--;j++;}res=Math.max(res,p);}
System.out.println(res);}}
