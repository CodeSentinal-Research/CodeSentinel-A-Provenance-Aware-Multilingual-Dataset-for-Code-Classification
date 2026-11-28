import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] a=new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        Arrays.sort(a);
        for(int i=0;i+1<n;i+=2){int t=a[i];a[i]=a[i+1];a[i+1]=t;}
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<n;i++){if(i>0)sb.append(' ');sb.append(a[i]);}
        System.out.println(sb);
    }
}
