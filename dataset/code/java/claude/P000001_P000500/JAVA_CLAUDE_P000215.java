import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),k=sc.nextInt();
        double[] a=new double[n];
        for(int i=0;i<n;i++) a[i]=sc.nextDouble();
        double win=0;
        for(int i=0;i<k;i++) win+=a[i];
        double best=win;
        for(int i=k;i<n;i++){win+=a[i]-a[i-k];best=Math.max(best,win);}
        System.out.printf("%.5f%n",best/k);
    }
}
