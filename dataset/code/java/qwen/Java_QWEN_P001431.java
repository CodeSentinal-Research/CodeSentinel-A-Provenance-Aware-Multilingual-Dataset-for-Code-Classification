import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] words = new String[n];
        for(int i=0; i<n; i++) words[i] = sc.next();
        
        Map<Integer, Integer> maskFreq = new HashMap<>();
        long count = 0;
        
        for(String w : words) {
            int mask = 0;
            for(char c : w.toCharArray()) {
                mask |= (1 << (c - 'a'));
            }
            count += maskFreq.getOrDefault(mask, 0);
            maskFreq.put(mask, maskFreq.getOrDefault(mask, 0) + 1);
        }
        System.out.println(count);
    }
}
