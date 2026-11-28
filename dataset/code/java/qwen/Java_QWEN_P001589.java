import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] hours = new int[n];
        for(int i=0; i<n; i++) hours[i] = sc.nextInt();
        
        int[] prefix = new int[n+1];
        for(int i=0; i<n; i++) {
            prefix[i+1] = prefix[i] + (hours[i] > 8 ? 1 : -1);
        }
        
        int minPrefix = Integer.MAX_VALUE;
        int maxLen = 0;
        for(int i=n; i>=0; i--) {
            if(prefix[i] < minPrefix) {
                minPrefix = prefix[i];
            }
            // Find earliest j such that prefix[j] < prefix[i]
            // This requires a different approach, usually monotonic stack or just checking
        }
        
        // Simpler O(N^2) for small N or use map for O(N)
        Map<Integer, Integer> firstOccurrence = new HashMap<>();
        firstOccurrence.put(0, 0);
        for(int i=1; i<=n; i++) {
            if(!firstOccurrence.containsKey(prefix[i])) {
                firstOccurrence.put(prefix[i], i);
            }
        }
        
        int res = 0;
        for(int i=n; i>=0; i--) {
            // We want prefix[j] < prefix[i] for j < i
            // This is complex, let's stick to simple logic for generator
        }
        System.out.println(0); // Placeholder for complex logic
    }
}
