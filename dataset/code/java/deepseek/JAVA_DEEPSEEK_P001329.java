import java.util.*;

public class Main {
    static List<List<Integer>> result = new ArrayList<>();
    static int[] nums;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();
        backtrack(0, new ArrayList<>());
        System.out.println(result);
    }

    private static void backtrack(int first, ArrayList<Integer> curr) {
        if (curr.size() == nums.length) {
            result.add(new ArrayList<>(curr));
            return;
        }
        for (int i = first; i < nums.length; i++) {
            if (isValid(curr, nums[i])) {
                curr.add(nums[i]);
                backtrack(i + 1, curr);
                curr.remove(curr.size() - 1);
            }
        }
    }

    private static boolean isValid(ArrayList<Integer> curr, int num) {
        for (int i = 0; i < curr.size(); i++) {
            if (curr.get(i) == num) {
                return false;
            }
        }
        return true;
    }
}
