import java.util.*;
public class Main {
    static int n;
    static boolean[] cols, diag1, diag2;
    static List<List<String>> res;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        cols = new boolean[n];
        diag1 = new boolean[2*n];
        diag2 = new boolean[2*n];
        res = new ArrayList<>();
        backtrack(0, new ArrayList<>());
        for(List<String> board : res) {
            for(String row : board) System.out.println(row);
            System.out.println();
        }
    }
    static void backtrack(int r, List<String> board) {
        if(r == n) {
            res.add(new ArrayList<>(board));
            return;
        }
        char[] row = new char[n];
        Arrays.fill(row, '.');
        for(int c=0; c<n; c++) {
            if(cols[c] || diag1[r+c] || diag2[r-c+n]) continue;
            cols[c] = diag1[r+c] = diag2[r-c+n] = true;
            row[c] = 'Q';
            board.add(new String(row));
            backtrack(r + 1, board);
            board.remove(board.size() - 1);
            row[c] = '.';
            cols[c] = diag1[r+c] = diag2[r-c+n] = false;
        }
    }
}
