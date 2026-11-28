import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static List<List<Integer>> result = new ArrayList<>();
    private static List<Integer> path = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        backtracking(1, k, n, 0, 0);
        System.out.println(result);
    }

    private static void backtracking(int start, int k, int n, int sum, int count) {
        if (count > k) {
            return;
        }
        if (count == k && sum == n) {
            result.add(new ArrayList<>(path));
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (sum + i > n) {
                break;
            }
            sum += i;
            path.add(i);
            backtracking(i + 1, k, n, sum, count + 1);
            sum -= i;
            path.remove(path.size() - 1);
        }
    }
}
