import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        insertionSort(nums, n);
        for (int num : nums) {
            System.out.print(num + " ");
        }
    }

    public static void insertionSort(int[] nums, int n) {
        if (n <= 1) {
            return;
        }
        insertionSort(nums, n - 1);
        int last = nums[n - 1];
        int j = n - 2;
        while (j >= 0 && nums[j] > last) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = last;
    }
}
