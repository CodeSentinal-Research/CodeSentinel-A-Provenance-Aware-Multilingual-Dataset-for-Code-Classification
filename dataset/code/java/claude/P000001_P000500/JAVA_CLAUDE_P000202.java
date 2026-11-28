import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Set<Integer> s=new HashSet<>();
        for(int i=0;i<n;i++) s.add(sc.nextInt());
        int best=0;
        for(int x:s){
            if(!s.contains(x-1)){
                int cur=1;
                while(s.contains(x+cur)) cur++;
                best=Math.max(best,cur);
            }
        }
        System.out.println(best);
    }
}
