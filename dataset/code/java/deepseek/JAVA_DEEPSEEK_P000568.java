import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        int x = Integer.parseInt(System.console().readLine());
        int y = Integer.parseInt(System.console().readLine());
        System.out.println(minKnightMoves(x, y));
    }

    private static int minKnightMoves(int x, int y) {
        x = Math.abs(x);
        y = Math.abs(y);
        if (x + y == 0) {
            return 0;
        }
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }
        if (y == 0) {
            return (x - 1) / 2;
        }
        if (x == 1 && y == 2) {
            return 2;
       }
        return (x * y + 1) / 2;
    }
}
