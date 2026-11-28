import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] a=new int[n]; for(int i=0;i<n;i++) a[i]=sc.nextInt();
        int e1=0,e2=1,c1=0,c2=0;
        for(int x:a){
            if(x==e1) c1++;
            else if(x==e2) c2++;
            else if(c1==0){e1=x;c1=1;}
            else if(c2==0){e2=x;c2=1;}
            else{c1--;c2--;}
        }
        c1=c2=0;
        for(int x:a){if(x==e1)c1++;else if(x==e2)c2++;}
        List<Integer> res=new ArrayList<>();
        if(c1>n/3) res.add(e1);
        if(c2>n/3) res.add(e2);
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<res.size();i++){if(i>0)sb.append(' ');sb.append(res.get(i));}
        System.out.println(sb);
    }
}
