import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static List<List<Integer>> result = new ArrayList<>();
    private static int[] candidates;
    private static int target;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        target = scanner.nextInt();
        candidates = new int[N];
        for (int i = 0; i < N; i++) {
            candidates[i] = scanner.nextInt();
        }
        Arrays.sort(candidates);
        backtracking(0, 0, new ArrayList<>());
        result.forEach(list -> {
            list.forEach(System.out::print);
            System.out.println();
        });
    }

    private static void backtracking(int start, int sum, List<Integer> list) {
        if (sum == target) {
            result.add(new ArrayList<>(list));
            return;
        }
        if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            list.add(candidates[i]);
            backtracking(i, sum + candidates[i], list);
            list.remove(list.size() - 1);
        }
    }
}
