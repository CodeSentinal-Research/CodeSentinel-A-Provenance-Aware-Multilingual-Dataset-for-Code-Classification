import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            String text = scanner.nextLine();
            String broken = scanner.hasNextLine() ? scanner.nextLine() : "";
            Set<Character> b = new HashSet<>();
            for (char c : broken.toCharArray()) b.add(c);
            int count = 0;
            for (String w : text.trim().split("\\s+")) {
                boolean ok = true;
                for (char c : w.toCharArray()) {
                    if (b.contains(c)) { ok = false; break; }
                }
                if (ok && !w.isEmpty()) count++;
            }
            System.out.println(count);
        }
    }
}