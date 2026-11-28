import java.util.*;
public class Main {
    static int N, M, count;
    static int[][] grid;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        grid = new int[N][M];
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++) grid[i][j] = sc.nextInt();
        count = 0;
        if(grid[0][0] == 1) backtrack(0, 0);
        System.out.println(count);
    }
    static void backtrack(int r, int c) {
        if(r == N-1 && c == M-1) {
            count++;
            return;
        }
        if(c + 1 < M && grid[r][c+1] == 1) backtrack(r, c + 1);
        if(r + 1 < N && grid[r+1][c] == 1) backtrack(r + 1, c);
    }
}
