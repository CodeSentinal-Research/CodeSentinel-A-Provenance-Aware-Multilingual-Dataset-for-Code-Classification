import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] board = new int[9][9];
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++) board[i][j] = sc.nextInt();
        
        boolean valid = true;
        
        // Check rows
        for(int i=0; i<9; i++) {
            boolean[] seen = new boolean[10];
            for(int j=0; j<9; j++) {
                if(seen[board[i][j]]) valid = false;
                seen[board[i][j]] = true;
            }
        }
        
        // Check cols
        for(int j=0; j<9; j++) {
            boolean[] seen = new boolean[10];
            for(int i=0; i<9; i++) {
                if(seen[board[i][j]]) valid = false;
                seen[board[i][j]] = true;
            }
        }
        
        // Check subgrids
        for(int r=0; r<9; r+=3) {
            for(int c=0; c<9; c+=3) {
                boolean[] seen = new boolean[10];
                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {
                        if(seen[board[r+i][c+j]]) valid = false;
                        seen[board[r+i][c+j]] = true;
                    }
                }
            }
        }
        
        System.out.println(valid ? "YES" : "NO");
    }
}
