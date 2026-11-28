import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(countCompleteSubarrays(arr, n));
    }

    public static long countCompleteSubarrays(int[] arr, int n) {
        Map<Integer, Integer> map = new HashMap<>();
        long count = 0;
        int distinctCount = 0;
        for (int i = 0; i < n; i++) {
            int num = arr[i];
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1);
            } else {
                map.put(num, 1);
                distinctCount++;
            }
            if (map.get(num) == 1) {
                count += distinctCount;
            }
        }
        return count;
    }
}
