import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        TreeSet<Long> s=new TreeSet<>();
        for(int i=0;i<n;i++){long x=sc.nextLong();s.add(x);if(s.size()>3)s.pollFirst();}
        System.out.println(s.size()==3?s.first():s.last());
    }
}
