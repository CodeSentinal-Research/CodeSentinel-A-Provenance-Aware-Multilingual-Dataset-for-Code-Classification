import java.util.HashMap;
import java.util.Scanner;

public class Main {
    HashMap<Integer, Boolean> memo = new HashMap<>();
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int maxChoosableInteger = scanner.nextInt();
        int desiredTotal = scanner.nextInt();
        Main main = new Main();
        System.out.println(main.canIWin(maxChoosableInteger, desiredTotal));
    }

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        return helper(maxChoosableInteger, desiredTotal, 0, 0);
    }

    private boolean helper(int m, int d, int used, int sum) {
        if (!memo.containsKey(used)) {
            boolean canWin = false;
            for (int i = 1; i <= m; i++) {
                if (((used >> i) & 1) == 0) {
                    if (sum + i >= d || !helper(m, d, used | (1 << i), sum + i)) {
                        canWin = true;
                        break;
                    }
                }
            }
            memo.put(used, canWin);
        }
        return memo.get(used);
    }
}
