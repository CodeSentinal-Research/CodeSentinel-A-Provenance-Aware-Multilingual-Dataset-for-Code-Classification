import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
       }
        HashMap<Integer, Integer> map = new HashMap<>();
        int distinctCount = 0;
        for (int i = 0; i < k; i++) {
            if (map.get(arr[i]) == null) {
                map.put(arr[i], 1);
                distinctCount++;
            } else {
                map.put(arr[i], map.get(arr[i]) + 1);
            }
        }
        System.out.print(distinctCount + " ");
        for (int i = k; i < n; i++) {
            if (map.get(arr[i - k]) == 1) {
                map.remove(arr[i - k]);
                distinctCount--;
            } else {
                map.put(arr[i - k], map.get(arr[i - k]) - 1);
            }
            if (map.get(arr[i]) == null) {
                map.put(arr[i], 1);
                distinctCount++;
            } else {
                map.put(arr[i], map.get(arr[i]) + 1);
            }
            System.out.print(distinctCount + " ");
        }
    }
}
