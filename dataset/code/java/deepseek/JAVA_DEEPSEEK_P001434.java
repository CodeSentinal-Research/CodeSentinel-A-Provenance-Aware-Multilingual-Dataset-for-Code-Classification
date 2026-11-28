import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < n; i++) {
            String[] moves = scanner.nextLine().split(" ");
            int row = Integer.parseInt(moves[0]);
            int col = Integer.parseInt(moves[1]);

            // Check if the move is valid
            if (row < 0 || row > 2 || col < 0 || col > 2) {
                System.out.println("Invalid move");
                return;
            }

            // Check if the game is over
            if (isGameOver(row, col)) {
                System.out.println("Game over");
                return;
            }
        }

        // If no game over, then it's a draw
        System.out.println("Draw");
    }

    private static boolean isGameOver(int row, int col) {
        // Check if the game is over based on the current move
        // For example, if the third row is full, then the game is over
        if (row == 2 && col == 2) {
            return true;
        }

        return false;
    }
}
