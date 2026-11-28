import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int target = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }

        List<Integer> result = findClosestElements(nums, K, target);
        for (int num : result) {
            System.out.print(num + " ");
        }
    }

    public static List<Integer> findClosestElements(int[] arr, int K, int X) {
        int left = 0;
        int right = arr.length - K;
        while (left < right) {
            int mid = (left + right) / 2;
            if (X - arr[mid] > arr[mid + K] - X) {
                left = mid + 1;
           } else {
                right = mid;
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int i = left; i < left + K; i++) {
            result.add(arr[i]);
        }
        return result;
    }
}
