import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        List<String> result = new ArrayList<>();
        dfs(n, m, "", result);
        Collections.sort(result);
        for (String path : result) {
            System.out.println(path);
        }
    }

    private static void dfs(int n, int m, String path, List<String> result) {
        if (n == 0 && m == 0) {
            result.add(path);
            return;
        }
        if (n > 0) {
            dfs(n - 1, m, path + "H" + n, result);
        }
        if (m > 0) {
            dfs(n, m - 1, path + "V" + m, result);
        }
        if (n > 0 && m > 0) {
            dfs(n - 1, m - 1, path + "D" + Math.min(n, m), result);
        }
    }
}
