import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();
        System.out.println(maxResult(nums, k));
    }

    public static int maxResult(int[] nums, int k) {
        int n = nums.length;
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        heap.add(new int[]{nums[0], 0});
        int max = nums[0];
        for (int i = 1; i < n; i++) {
            while (heap.peek()[1] < i - k) {
                heap.poll();
            }
            max = Math.max(max, heap.peek()[0] + nums[i]);
            heap.add(new int[]{max, i});
       }
        return max;
    }
}
