import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int target = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();
        Set<List<Integer>> result = new HashSet<>();
        backtrack(nums, target, 0, new ArrayList<>(), result);
        for (List<Integer> list : result) {
            System.out.println(list);
        }
    }

    private static void backtrack(int[] nums, int target, int start, List<Integer> current, Set<List<Integer>> result) {
        if (current.size() > 0 && current.size() + nums.length - start < target) {
            return;
        }
        if (current.size() == target) {
            if (current.stream().mapToInt(Integer::intValue).sum() == target) {
                result.add(new ArrayList<>(current));
            }
            return;
        }
        for (int i = start; i < nums.length; i++) {
            current.add(nums[i]);
            backtrack(nums, target, i + 1, current, result);
            current.remove(current.size() - 1);
        }
    }
}
