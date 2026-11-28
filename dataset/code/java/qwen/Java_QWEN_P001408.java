import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] changed = new int[n];
        for(int i=0; i<n; i++) changed[i] = sc.nextInt();
        
        if(n % 2 != 0) {
            System.out.println("-1");
            return;
        }
        
        Arrays.sort(changed);
        Map<Integer, Integer> freq = new HashMap<>();
        for(int num : changed) freq.put(num, freq.getOrDefault(num, 0) + 1);
        
        List<Integer> res = new ArrayList<>();
        for(int num : changed) {
            if(freq.getOrDefault(num, 0) == 0) continue;
            freq.put(num, freq.get(num) - 1);
            if(freq.getOrDefault(num * 2, 0) == 0) {
                System.out.println("-1");
                return;
            }
            freq.put(num * 2, freq.get(num * 2) - 1);
            res.add(num);
        }
        
        for(int x : res) System.out.print(x + " ");
    }
}
