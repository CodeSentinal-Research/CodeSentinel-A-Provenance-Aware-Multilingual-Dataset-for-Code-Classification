import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public static int maxLenEqualPosNeg(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int prefixSum = 0;
        int maxLen = 0;
        for (int i = 0; i < arr.length; i++) {
            int val = arr[i] > 0 ? 1 : (arr[i] < 0 ? -1 : 0);
            prefixSum += val;
            if (map.containsKey(prefixSum)) {
                maxLen = Math.max(maxLen, i - map.get(prefixSum));
            } else {
                map.put(prefixSum, i);
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
            System.out.println(maxLenEqualPosNeg(arr));
        }
        sc.close();
    }
}