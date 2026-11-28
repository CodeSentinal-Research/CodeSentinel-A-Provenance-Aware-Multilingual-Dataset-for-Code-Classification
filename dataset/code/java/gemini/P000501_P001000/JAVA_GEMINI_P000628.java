import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int q = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            int cursor = 0;
            while (q-- > 0) {
                String cmd = scanner.next();
                if (cmd.equals("addText")) {
                    String s = scanner.next();
                    sb.insert(cursor, s);
                    cursor += s.length();
                } else if (cmd.equals("deleteText")) {
                    int k = scanner.nextInt();
                    int delCnt = Math.min(k, cursor);
                    sb.delete(cursor - delCnt, cursor);
                    cursor -= delCnt;
                    System.out.println(delCnt);
                } else if (cmd.equals("cursorLeft")) {
                    int k = scanner.nextInt();
                    cursor = Math.max(0, cursor - k);
                    int l = Math.max(0, cursor - 10);
                    System.out.println(sb.substring(l, cursor));
                } else if (cmd.equals("cursorRight")) {
                    int k = scanner.nextInt();
                    cursor = Math.min(sb.length(), cursor + k);
                    int l = Math.max(0, cursor - 10);
                    System.out.println(sb.substring(l, cursor));
                }
            }
        }
    }
}