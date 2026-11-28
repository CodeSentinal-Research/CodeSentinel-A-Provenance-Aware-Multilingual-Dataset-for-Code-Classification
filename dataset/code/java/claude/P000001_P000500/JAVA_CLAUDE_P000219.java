import java.util.*;
public class Solution{
public static void main(String[] a){
Scanner sc=new Scanner(System.in);
int n=sc.nextInt(),k=sc.nextInt();
long[]arr=new long[n];for(int i=0;i<n;i++)arr[i]=sc.nextLong();
long p=1;for(int i=n-k;i<n;i++)p*=arr[i];System.out.println(p);}}
