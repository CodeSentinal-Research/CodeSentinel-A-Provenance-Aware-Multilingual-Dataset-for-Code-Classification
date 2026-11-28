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
       
        Set<List<Integer>> result = findPairs(nums, target);
        for (List<Integer> pair : result) {
            System.out.println(pair.get(0) + " " + pair.get(1));
        }
    }

    public static Set<List<Integer>> findPairs(int[] nums, int target) {
        Set<List<Integer>> result = new HashSet<>();
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            int complement = target - num;
            if (map.containsKey(complement)) {
                result.add(Arrays.asList(complement, num));
            } else {
                map.put(num, complement);
            }
        }
        return result;
    }
}
