import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int target = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        long count = 0;
        for (int i = 0; i < n - 2; i++) {
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int j = i + 1; j < n; j++) {
                int complement = target - arr[i] - arr[j];
                if (map.containsKey(complement)) {
                    count += map.get(complement);
                }
                map.put(arr[j], map.getOrDefault(arr[j], 0) + 1);
            }
        }
        System.out.println(count);
    }
}
