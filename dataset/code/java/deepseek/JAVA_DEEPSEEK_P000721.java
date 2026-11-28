import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        List<List<Integer>> res = findSubsequences(nums);
        for (List<Integer> list : res) {
            for (Integer num : list) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

    public static List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        dfs(nums, 0, path, result);
        return result;
    }

    public static void dfs(int[] nums, int start, List<Integer> path, List<List<Integer>> result) {
        if (path.size() > 1) {
            result.add(new ArrayList<>(path));
        }
        Set<Integer> used = new HashSet<>();
        for (int i = start; i < nums.length; i++) {
            if (used.contains(nums[i])) {
                continue;
           
            }
            used.add(nums[i]);
            path.add(nums[i]);
            dfs(nums, i+1, path, result);
            path.remove(path.size() - 1);
        }
    }
}
