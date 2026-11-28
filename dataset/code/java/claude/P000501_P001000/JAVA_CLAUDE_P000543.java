/* P000543: Data Stream as Disjoint Intervals */
import java.util.*;
public class Solution{
    static TreeMap<Integer,Integer> map=new TreeMap<>();
    static void add(int v){
        int lo=v,hi=v;
        Integer floor=map.floorKey(v+1);
        while(floor!=null&&map.get(floor)>=v-1){
            lo=Math.min(lo,floor);hi=Math.max(hi,map.get(floor));
            map.remove(floor);floor=map.floorKey(v+1);
        }
        map.put(lo,hi);
    }
    public static void main(String[]a){
        Scanner sc=new Scanner(System.in);int q=sc.nextInt();sc.nextLine();
        while(q-->0){String line=sc.nextLine().trim();
            if(line.startsWith("addNum")){add(Integer.parseInt(line.split(" ")[1]));}
            else{StringBuilder sb=new StringBuilder();for(Map.Entry<Integer,Integer>e:map.entrySet())sb.append("[").append(e.getKey()).append(",").append(e.getValue()).append("] ");System.out.println(sb.toString().trim());}
        }
    }
}
