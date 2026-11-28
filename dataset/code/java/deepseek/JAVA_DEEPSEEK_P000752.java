import java.util.*;

public class Main {
    static boolean findPart = false;
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int target = scanner.nextInt();
        findSubsequence(nums, target, 0, 0, new ArrayList<>());
        if (!findPart) {
            System.out.println(-1);
        }
    }

    private static void findSubsequence(int[] nums, int target, int sum, int start, List<Integer> list) {
        if (findPart) return;
        if (sum > target) return;
        if (sum == target) {
            findPart = true;
            for (int num : list) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        for (int i = start; i < nums.length; i++) {
            list.add(nums[i]);
            findSubsequence(nums, target, sum + nums[i], i + 1, list);
            list.remove(list.size() - 1);
        }
    }
}
