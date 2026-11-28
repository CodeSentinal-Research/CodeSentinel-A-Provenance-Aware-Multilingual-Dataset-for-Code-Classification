import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int key = scanner.nextInt();
        System.out.println(mostFrequentNumberFollowingKey(arr, key));
    }

    public static int mostFrequentNumberFollowingKey(int[] arr, int key) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }
        int maxCount = 0;
        int mostFrequentNumber = -1;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() > maxCount) {
                maxCount = entry.getValue();
                mostFrequentNumber = entry.getKey();
            }
        }
        return mostFrequentNumber;
    }
}
