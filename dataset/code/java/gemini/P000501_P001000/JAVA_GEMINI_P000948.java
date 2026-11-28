import java.util.Scanner;

public class Solution {
    public static String chessboardGame(int x, int y) {
        x = (x - 1) % 4;
        y = (y - 1) % 4;
        if ((x == 0 || x == 1) && (y == 0 || y == 1)) {
            return "Second";
        }
        return "First";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                System.out.println(chessboardGame(x, y));
            }
        }
        sc.close();
    }
}