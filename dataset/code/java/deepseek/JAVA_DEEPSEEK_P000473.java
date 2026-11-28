import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int target = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(search(nums, target));
    }

    public static int search(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
            if (i > 0 && nums[i - 1] == target) {
                return i - 1;
            }
            if (i < nums.length - 1 && nums[i + 1] == target) {
                return i + 1;
            }
        }
        return -1;
    }
}
