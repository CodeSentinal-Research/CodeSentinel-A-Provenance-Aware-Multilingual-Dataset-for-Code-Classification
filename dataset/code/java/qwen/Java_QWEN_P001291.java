import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] hand = new int[n];
        for(int i=0; i<n; i++) hand[i] = sc.nextInt();
        
        if(n % k != 0) { System.out.println("NO"); return; }
        
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int card : hand) map.put(card, map.getOrDefault(card, 0) + 1);
        
        while(!map.isEmpty()) {
            int first = map.firstKey();
            for(int i=0; i<k; i++) {
                int curr = first + i;
                if(!map.containsKey(curr) || map.get(curr) == 0) {
                    System.out.println("NO");
                    return;
                }
                map.put(curr, map.get(curr) - 1);
                if(map.get(curr) == 0) map.remove(curr);
            }
        }
        System.out.println("YES");
    }
}
