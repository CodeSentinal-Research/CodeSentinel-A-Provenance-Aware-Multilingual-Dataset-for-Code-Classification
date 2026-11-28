import java.util.*;
public class Solution {
    static class Win {
        List<String> hist = new ArrayList<>();
        int cur = 0;
        Win(String home) { hist.add(home); }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            Map<Integer, Win> wins = new HashMap<>();
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("newWindow")) {
                    int id = scanner.nextInt();
                    String home = scanner.next();
                    wins.put(id, new Win(home));
                } else if (cmd.equals("visit")) {
                    int id = scanner.nextInt();
                    String url = scanner.next();
                    Win w = wins.get(id);
                    while (w.hist.size() > w.cur + 1) w.hist.remove(w.hist.size() - 1);
                    w.hist.add(url);
                    w.cur++;
                } else if (cmd.equals("back")) {
                    int id = scanner.nextInt(), steps = scanner.nextInt();
                    Win w = wins.get(id);
                    w.cur = Math.max(0, w.cur - steps);
                    System.out.println(w.hist.get(w.cur));
                } else if (cmd.equals("forward")) {
                    int id = scanner.nextInt(), steps = scanner.nextInt();
                    Win w = wins.get(id);
                    w.cur = Math.min(w.hist.size() - 1, w.cur + steps);
                    System.out.println(w.hist.get(w.cur));
                } else if (cmd.equals("currentPage")) {
                    int id = scanner.nextInt();
                    System.out.println(wins.get(id).hist.get(wins.get(id).cur));
                } else if (cmd.equals("closeWindow")) {
                    wins.remove(scanner.nextInt());
                }
            }
        }
    }
}