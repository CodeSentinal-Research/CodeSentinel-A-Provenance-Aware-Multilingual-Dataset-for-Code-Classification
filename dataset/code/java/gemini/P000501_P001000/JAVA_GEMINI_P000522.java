import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String home = scanner.next();
            int q = scanner.nextInt();
            List<String> history = new ArrayList<>();
            history.add(home);
            int curr = 0;
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("visit")) {
                    String url = scanner.next();
                    while (history.size() > curr + 1) history.remove(history.size() - 1);
                    history.add(url);
                    curr++;
                } else if (cmd.equals("back")) {
                    int steps = scanner.nextInt();
                    curr = Math.max(0, curr - steps);
                    System.out.println(history.get(curr));
                } else if (cmd.equals("forward")) {
                    int steps = scanner.nextInt();
                    curr = Math.min(history.size() - 1, curr + steps);
                    System.out.println(history.get(curr));
                }
            }
        }
    }
}