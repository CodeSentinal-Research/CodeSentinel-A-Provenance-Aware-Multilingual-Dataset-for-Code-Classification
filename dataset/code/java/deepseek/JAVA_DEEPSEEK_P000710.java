import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        generatePermutations(nums, 0);
    }

    private static void generatePermutations(int[] nums, int start) {
        if (start == nums.length) {
            for (int num : nums) {
                System.out.println(num);
            }
            System.out.println();
        } else {
            for (int i = start; i < nums.length; i++) {
                swap(nums, start, i);
                generatePermutations(nums, start + 1);
                swap(nums, start, i);
            }
        }
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
