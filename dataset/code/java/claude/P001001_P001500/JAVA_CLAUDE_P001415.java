import java.util.*;
public class Solution {
    public Map<Integer,Integer> frequency(int[] arr) {
        Map<Integer,Integer> map = new TreeMap<>();
        for (int x : arr) map.merge(x, 1, Integer::sum);
        return map;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt(); int[] arr=new int[n];
        for (int i=0;i<n;i++) arr[i]=sc.nextInt();
        new Solution().frequency(arr).forEach((k,v)->System.out.println(k+": "+v));
    }
}
