import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        selectionSort(nums, 0, n-1);
        for (int num : nums) {
            System.out.print(num + " ");
        }
    }

    private static void selectionSort(int[] nums, int start, int end) {
        if (start < end) {
            int minIndex = start;
            for (int i = start + 1; i <= end; i++) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
           
               int temp = nums[minIndex];
               nums[minIndex] = nums[start];
               nums[start] = temp;
               selectionSort(nums, start + 1, end);
           }
        }
    }
}
