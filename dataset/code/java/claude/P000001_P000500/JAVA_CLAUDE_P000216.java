import java.util.*;
public class Solution {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Map<Integer,Integer> freq=new HashMap<>(),first=new HashMap<>(),last=new HashMap<>();
        for(int i=0;i<n;i++){
            int x=sc.nextInt();
            freq.merge(x,1,Integer::sum);
            first.putIfAbsent(x,i);
            last.put(x,i);
        }
        int deg=freq.values().stream().max(Integer::compare).orElse(0);
        int res=n;
        for(Map.Entry<Integer,Integer> e:freq.entrySet())
            if(e.getValue()==deg) res=Math.min(res,last.get(e.getKey())-first.get(e.getKey())+1);
        System.out.println(res);
    }
}
