import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        int[] count = new int[2000001]; // Offset for negative numbers if needed, but constraints say generic
        
        // Using HashMap for generic integers
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            freqMap.put(arr[i], freqMap.getOrDefault(arr[i], 0) + 1);
        }
        
        for (int num : arr) {
            if (freqMap.get(num) == 1) {
                System.out.println(num);
                return;
            }
        }
        System.out.println(-1);
    }
}
