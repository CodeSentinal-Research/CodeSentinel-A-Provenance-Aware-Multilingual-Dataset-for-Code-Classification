import java.util.*;

public class Main {
    static int N;
    static String[] words;
    static boolean[] visited;
    static ArrayList<Character> order;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        words = new String[N];
        visited = new boolean[N];
        order = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            words[i] = sc.next();
        }

        if (isValid()) {
            for (char c : order) {
                System.out.print(c);
            }
            System.out.println();
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }

    private static boolean isValid() {
        for (int i = 0; i < N; i++) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }

    private static boolean dfs(int index) {
        if (visited[index]) {
            return true;
        }
        visited[index] = true;
        char lastChar = words[index].charAt(0);
        for (int i = 1; i < words[index].length(); i++) {
            if (words[index].charAt(i) < lastChar) {
                return false;
            }
            lastChar = words[index].charAt(i);
        }
        order.add(lastChar);
        return dfs(index + 1);
    }
}
