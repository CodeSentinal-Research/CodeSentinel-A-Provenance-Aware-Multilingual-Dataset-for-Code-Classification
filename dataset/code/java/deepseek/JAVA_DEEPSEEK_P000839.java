import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nAndNumbers = br.readLine().split(" ");
        int n = Integer.parseInt(nAndNumbers[0]);
        int threshold = Integer.parseInt(nAndNumbers[1]);
        String[] numbers = br.readLine().split(" ");
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(numbers[i]);
        }
        System.out.println(smallestDivisor(nums, threshold));
    }

    public static int smallestDivisor(int[] nums, int threshold) {
        int left = 1;
        int right = (int)1e6;
        while (left < right) {
            int mid = (left + right) / 2;
            if (sum(nums, mid) <= threshold) {
                right = mid;
           } else {
                left = mid + 1;
            }
        }
        return right;
    }

    public static int sum(int[] nums, int divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }
}
