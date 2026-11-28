import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(totalNQueens(n));
    }

    public static int totalNQueens(int n) {
        int[] queens = new int[n];
        return totalNQueens(queens, 0);
    }

    private static int totalNQueens(int[] queens, int xy) {
        if (xy == queens.length) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < queens.length; i++) {
            queens[xy] = i;
            if (isValid(queens, xy)) {
                count += totalNQueens(queens, xy + 1);
           }
        }
        return count;
    }

    private static boolean isValid(int[] queens, int xy) {
        for (int i = 0; i < xy; i++) {
            if (queens[i] == queens[xy] || Math.abs(queens[i] - queens[xy]) == Math.abs(i - xy)) {
                return false;
            }
        }
        return true;
    }
}
