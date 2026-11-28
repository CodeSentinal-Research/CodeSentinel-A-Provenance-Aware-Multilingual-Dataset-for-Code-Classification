import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        HashMap<Integer, Integer> firstOccurrence = new HashMap<>();
        int firstRepeating = -1;
        
        for (int i = 0; i < n; i++) {
            if (firstOccurrence.containsKey(arr[i])) {
                if (firstRepeating == -1 || firstOccurrence.get(arr[i]) < firstRepeating) {
                    // We want the element that appears first in the array among duplicates
                    // Actually, problem says "first repeating element... appears first when traversing left to right"
                    // This usually means the duplicate whose second occurrence is earliest? 
                    // Or the value that repeats first? Standard interpretation: value whose second occurrence is earliest.
                    // Let's stick to simple: first value seen twice.
                }
            } else {
                firstOccurrence.put(arr[i], i);
            }
        }
        
        // Re-evaluating standard "First Repeating Element":
        // Usually means the element that repeats first.
        HashMap<Integer, Boolean> seen = new HashMap<>();
        for (int num : arr) {
            if (seen.containsKey(num)) {
                System.out.println(num);
                return;
            }
            seen.put(num, true);
        }
        System.out.println(-1);
    }
}
