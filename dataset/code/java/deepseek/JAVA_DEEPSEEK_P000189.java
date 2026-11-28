import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println(maxCircularSubarraySum(arr));
    }

    public static int maxCircularSubarraySum(int[] arr) {
        int n = arr.length;
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }
        int maxNormal = maxSubarraySum(arr, n);
        if (maxNormal < 0) {
            return maxNormal;
        }
        int maxCircular = 0;
        for (int i = 0; i < n; i++) {
            maxCircular += arr[i];
            arr[i] = -arr[i];
        }
        int minNormal = maxSubarraySum(arr, n);
        maxCircular = totalSum + minNormal;
        return Math.max(maxNormal, maxCircular);
    }

    public static int maxSubarraySum(int[] arr, int n) {
        int maxSoFar = Integer.MIN_VALUE, maxEndingHere = 0;
        for (int i = 0; i < n; i++) {
            maxEndingHere = maxEndingHere + arr[i];
            if (maxSoFar < maxEndingHere) {
                maxSoFar = maxEndingHere;
            }
            if (maxEndingHere < 0) {
                maxEndingHere = 0;
            }
        }
        return maxSoFar;
    }
}
