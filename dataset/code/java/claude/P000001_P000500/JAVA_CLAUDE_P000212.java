import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),k=sc.nextInt();
        int[] a=new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        for(int i=0;i<n;i++)
            if(a[i]==0&&(i==0||a[i-1]==0)&&(i==n-1||a[i+1]==0)){a[i]=1;k--;}
        System.out.println(k<=0?"true":"false");
    }
}
