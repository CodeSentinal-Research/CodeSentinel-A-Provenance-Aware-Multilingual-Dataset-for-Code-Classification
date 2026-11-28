import java.util.*;
public class Solution{public static void main(String[]a){Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();double[]arr=new double[n];for(int i=0;i<n;i++)arr[i]=sc.nextDouble();int k=sc.nextInt();
    double s=0;for(int i=0;i<k;i++)s+=arr[i];double best=s;
    for(int i=k;i<n;i++){s+=arr[i]-arr[i-k];best=Math.max(best,s);}System.out.println(best/k);}}
