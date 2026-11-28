import java.util.*;

public class Main {
    static List<List<Integer>> result;
    static List<Integer> current;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<Integer> nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextInt());
        }
        result = new ArrayList<>();
        current = new ArrayList<>();
        backtrack(nums);
        Collections.sort(result, Comparator.comparing(o -> o.toString()));
        for (List<Integer> list : result) {
            System.out.println(list.toString().replaceAll("\\[|\\]", "").replaceAll(" ", ""));
        }
    }

    private static void backtrack(List<Integer> nums) {
        if (current.size() == nums.size()) {
            result.add(new ArrayList<>(current));
            return;
        }
        for (int num : nums) {
            if (current.contains(num)) continue;
            current.add(num);
            backtrack(nums);
            current.remove(current.size() - 1);
        }
    }
}
