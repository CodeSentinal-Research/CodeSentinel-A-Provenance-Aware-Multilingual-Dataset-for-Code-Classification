import java.util.*;

public class Main {
    static int maxLength = 0;
    static Set<String> set = new HashSet<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String str = scanner.nextLine();
            set.clear();
            dfs(str, 0, "");
        }

        System.out.println(maxLength);
    }

    private static void dfs(String str, int index, String path) {
        if (index == str.length()) {
            if (set.contains(path)) {
                return;
            }
            maxLength = Math.max(maxLength, path.length());
            set.add(path);
            return;
        }

        for (int i = index; i < str.length(); i++) {
            if (set.contains(str.substring(index, i + 1))) {
                continue;
            }
            set.add(str.substring(index, i + 1));
            dfs(str, i + 1, path + str.charAt(i));
        }
    }
}
