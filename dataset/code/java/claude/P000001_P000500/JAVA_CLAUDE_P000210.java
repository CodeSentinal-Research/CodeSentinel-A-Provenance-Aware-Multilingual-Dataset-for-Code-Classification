import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] a=new int[n],b=new int[n],c=new int[n];
        for(int i=0;i<n;i++) a[i]=sc.nextInt();
        for(int i=0;i<n;i++) b[i]=sc.nextInt();
        for(int i=0;i<n;i++) c[i]=sc.nextInt();
        int i=0,j=0,k=0;
        List<Integer> res=new ArrayList<>();
        while(i<n&&j<n&&k<n){
            if(a[i]==b[j]&&b[j]==c[k]){res.add(a[i]);i++;j++;k++;}
            else if(a[i]<=b[j]&&a[i]<=c[k]) i++;
            else if(b[j]<=a[i]&&b[j]<=c[k]) j++;
            else k++;
        }
        StringBuilder sb=new StringBuilder();
        for(int idx=0;idx<res.size();idx++){if(idx>0)sb.append(' ');sb.append(res.get(idx));}
        System.out.println(sb);
    }
}
