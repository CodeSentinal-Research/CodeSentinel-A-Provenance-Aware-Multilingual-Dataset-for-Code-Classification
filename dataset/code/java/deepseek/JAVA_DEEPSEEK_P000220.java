import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] knows = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                knows[i][j] = scanner.nextInt();
            }
        }
        System.out.println(findCelebrity(knows, n));
    }

    static int findCelebrity(int[][] knows, int n) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            stack.push(i);
        }
        while (stack.size() > 1) {
            int a = stack.pop();
            int b = stack.pop();
            if (knows[a][b] == 1) {
                stack.push(b);
            } else {
                stack.push(a);
           }
        }
        int candidate = stack.pop();
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (knows[candidate][i] == 1 || knows[i][candidate] == 0) {
                    return -1;
                }
            }
        }
        return candidate;
    }
}
