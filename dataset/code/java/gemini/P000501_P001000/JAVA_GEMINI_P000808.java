import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public static int maxLenEqualEvenOdd(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int prefix = 0;
        int maxLen = 0;
        for (int i = 0; i < arr.length; i++) {
            prefix += (arr[i] % 2 == 0 ? 1 : -1);
            if (map.containsKey(prefix)) {
                maxLen = Math.max(maxLen, i - map.get(prefix));
            } else {
                map.put(prefix, i);
            }
        }
        return maxLen;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(maxLenEqualEvenOdd(arr));
        }
        sc.close();
    }
}