import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] moves = new int[n][2];
        for(int i=0; i<n; i++) {
            moves[i][0] = sc.nextInt();
            moves[i][1] = sc.nextInt();
        }
        
        char[][] board = new char[3][3];
        for(int i=0; i<3; i++) Arrays.fill(board[i], '.');
        
        String winner = "";
        for(int i=0; i<n; i++) {
            int r = moves[i][0];
            int c = moves[i][1];
            board[r][c] = (i % 2 == 0) ? 'X' : 'O';
            
            if(checkWin(board, 'X')) winner = "A";
            if(checkWin(board, 'O')) winner = "B";
        }
        
        if(!winner.isEmpty()) System.out.println(winner);
        else if(n == 9) System.out.println("Draw");
        else System.out.println("Pending");
    }
    
    static boolean checkWin(char[][] b, char p) {
        for(int i=0; i<3; i++) {
            if(b[i][0]==p && b[i][1]==p && b[i][2]==p) return true;
            if(b[0][i]==p && b[1][i]==p && b[2][i]==p) return true;
        }
        if(b[0][0]==p && b[1][1]==p && b[2][2]==p) return true;
        if(b[0][2]==p && b[1][1]==p && b[2][0]==p) return true;
        return false;
    }
}
