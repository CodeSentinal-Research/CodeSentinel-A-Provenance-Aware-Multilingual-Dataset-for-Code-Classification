import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    private static Set<Set<Integer>> result = new HashSet<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();

        Arrays.sort(nums);
        backtrack(nums, new HashSet<>(), 0);

        for (Set<Integer> set : result) {
            for (Integer num : set) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

    private static void backtrack(int[] nums, Set<Integer> current, int start) {
        result.add(new HashSet<>(current));
        for (int i = start; i < nums.length; i++) {
            current.add(nums[i]);
            backtrack(nums, current, i + 1);
            current.remove(nums[i]);
        }
    }
}
