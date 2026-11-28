import java.util.*;
public class Main {
    static int N, M;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        backtrack(0, 0, new StringBuilder());
    }
    static void backtrack(int r, int c, StringBuilder path) {
        if(r == N-1 && c == M-1) {
            System.out.println(path.toString());
            return;
        }
        if(c + 1 < M) {
            path.append('H');
            backtrack(r, c + 1, path);
            path.deleteCharAt(path.length() - 1);
        }
        if(r + 1 < N) {
            path.append('V');
            backtrack(r + 1, c, path);
            path.deleteCharAt(path.length() - 1);
        }
        if(r + 1 < N && c + 1 < M) {
            path.append('D');
            backtrack(r + 1, c + 1, path);
            path.deleteCharAt(path.length() - 1);
        }
    }
}
