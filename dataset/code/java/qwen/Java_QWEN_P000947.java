import java.util.*;
public class Main {
    static Map<Integer, Boolean> memo = new HashMap<>();
    static int maxChoosable;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        maxChoosable = sc.nextInt();
        int desiredTotal = sc.nextInt();
        
        if(desiredTotal <= 0) { System.out.println("true"); return; }
        if(maxChoosable * (maxChoosable + 1) / 2 < desiredTotal) { System.out.println("false"); return; }
        
        System.out.println(canWin(0, desiredTotal));
    }
    static boolean canWin(int usedMask, int remaining) {
        if(memo.containsKey(usedMask)) return memo.get(usedMask);
        
        for(int i=1; i<=maxChoosable; i++) {
            int bit = 1 << (i-1);
            if((usedMask & bit) == 0) {
                if(i >= remaining || !canWin(usedMask | bit, remaining - i)) {
                    memo.put(usedMask, true);
                    return true;
                }
            }
        }
        memo.put(usedMask, false);
        return false;
    }
}
