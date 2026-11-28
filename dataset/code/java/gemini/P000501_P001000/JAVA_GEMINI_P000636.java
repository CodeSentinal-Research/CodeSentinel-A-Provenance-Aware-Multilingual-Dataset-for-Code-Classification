import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            List<String> tabs = new ArrayList<>();
            int curIdx = 0;
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("open")) {
                    tabs.add(scanner.next());
                    curIdx = tabs.size() - 1;
                } else if (cmd.equals("close")) {
                    int i = scanner.nextInt();
                    tabs.remove(i);
                    if (curIdx >= tabs.size()) curIdx = Math.max(0, tabs.size() - 1);
                } else if (cmd.equals("switch")) {
                    curIdx = scanner.nextInt();
                } else if (cmd.equals("moveLeft")) {
                    int i = scanner.nextInt();
                    if (i > 0) {
                        Collections.swap(tabs, i, i - 1);
                        if (curIdx == i) curIdx = i - 1;
                        else if (curIdx == i - 1) curIdx = i;
                    }
                } else if (cmd.equals("moveRight")) {
                    int i = scanner.nextInt();
                    if (i < tabs.size() - 1) {
                        Collections.swap(tabs, i, i + 1);
                        if (curIdx == i) curIdx = i + 1;
                        else if (curIdx == i + 1) curIdx = i;
                    }
                } else if (cmd.equals("current")) {
                    System.out.println(tabs.isEmpty() ? "" : tabs.get(curIdx));
                }
            }
        }
    }
}