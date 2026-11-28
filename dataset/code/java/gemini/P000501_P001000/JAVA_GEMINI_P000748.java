import java.util.*;
public class Solution {
    static void diceRolls(int target, List<Integer> cur) {
        if (target == 0) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < cur.size(); i++) sb.append(cur.get(i)).append(i + 1 == cur.size() ? "" : " ");
            System.out.println(sb.toString());
            return;
        }
        for (int i = 1; i <= 6 && i <= target; i++) {
            cur.add(i);
            diceRolls(target - i, cur);
            cur.remove(cur.size() - 1);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            diceRolls(scanner.nextInt(), new ArrayList<>());
        }
    }
}