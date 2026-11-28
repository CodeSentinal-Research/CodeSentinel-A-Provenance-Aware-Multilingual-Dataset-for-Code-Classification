import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] a=new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        Arrays.sort(a);
        long opt1=(long)a[n-1]*a[n-2]*a[n-3];
        long opt2=(long)a[0]*a[1]*a[n-1];
        System.out.println(Math.max(opt1,opt2));
    }
}
