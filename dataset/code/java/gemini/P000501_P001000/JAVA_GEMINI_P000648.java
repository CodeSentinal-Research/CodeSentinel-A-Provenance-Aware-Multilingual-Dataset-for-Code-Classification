import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            List<String> history = new ArrayList<>();
            history.add("");
            int cur = 0;
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("type")) {
                    String s = scanner.next();
                    while (history.size() > cur + 1) history.remove(history.size() - 1);
                    history.add(history.get(history.size() - 1) + s);
                    cur++;
                } else if (cmd.equals("undo")) {
                    if (cur > 0) cur--;
                } else if (cmd.equals("redo")) {
                    if (cur + 1 < history.size()) cur++;
                } else if (cmd.equals("print")) {
                    System.out.println(history.get(cur));
                }
            }
        }
    }
}