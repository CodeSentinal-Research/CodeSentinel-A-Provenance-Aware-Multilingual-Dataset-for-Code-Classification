import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        int[][] dungeon = new int[R][C];
        int[][] minHealth = new int[R][C];

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                dungeon[i][j] = scanner.nextInt();
                minHealth[i][j] = Integer.MAX_VALUE;
            }
        }

        minHealth[R - 1][C - 1] = Math.max(1, 1 + dungeon[R - 1][C - 1]);

        for (int i = R - 1; i >= 0; i--) {
            for (int j = C - 1; j >= 0; j--) {
                if (i < R - 1) {
                    minHealth[i][j] = Math.min(minHealth[i][j], Math.max(1, minHealth[i + 1][j] + dungeon[i][j]));
                }
                if (j < C - 1) {
                    minHealth[i][j] = Math.min(minHealth[i][j], Math.max(1, minHealth[i][j + 1] + dungeon[i][j]));
                }
            }
        }

        System.out.println(minHealth[0][0]);
    }
}
