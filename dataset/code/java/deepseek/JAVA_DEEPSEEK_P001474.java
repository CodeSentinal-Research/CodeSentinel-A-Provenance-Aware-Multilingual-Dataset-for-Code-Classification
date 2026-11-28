import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int target = scanner.nextInt();
        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextInt());
        }
        List<List<Integer>> result = fourSum(nums, target);
        for (List<Integer> quad : result) {
            System.out.println(quad.get(0) + " " + quad.get(1) + " " + quad.get(2) + " " + quad.get(3));
        }
    }

    public static List<List<Integer>> fourSum(List<Integer> nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.size() < 4) {
            return result;
        }
        Collections.sort(nums);
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums.get(i) == nums.get(i - 1)) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums.get(j) == nums.get(j - 1)) {
                    continue;
                }
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    if (nums.get(i) + nums.get(j) + nums.get(left) + nums.get(right) == target) {
                        result.add(Arrays.asList(nums.get(i), nums.get(j), nums.get(left), nums.get(right)));
                        while (left < right && nums.get(left) == nums.get(left + 1)) {
                            left++;
                        }
                        while (left < right && nums.get(right) == nums.get(right - 1)) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (nums.get(i) + nums.get(j) + nums.get(left) + nums.get(right) < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return result;
    }
}
