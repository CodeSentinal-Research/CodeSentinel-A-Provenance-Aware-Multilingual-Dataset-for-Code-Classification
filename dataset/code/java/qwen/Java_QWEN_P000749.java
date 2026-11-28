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
        for(int i=1; i<=M-c-1; i++) {
            path.append("H").append(i);
            backtrack(r, c + i, path);
            path.setLength(path.length() - (String.valueOf(i).length() + 1));
        }
        for(int i=1; i<=N-r-1; i++) {
            path.append("V").append(i);
            backtrack(r + i, c, path);
            path.setLength(path.length() - (String.valueOf(i).length() + 1));
        }
        for(int i=1; i<=Math.min(N-r-1, M-c-1); i++) {
            path.append("D").append(i);
            backtrack(r + i, c + i, path);
            path.setLength(path.length() - (String.valueOf(i).length() + 1));
        }
    }
}
