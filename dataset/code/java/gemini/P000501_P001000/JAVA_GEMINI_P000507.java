import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            String[] nodes = s.split(",");
            int slots = 1;
            boolean valid = true;
            for (String node : nodes) {
                slots--;
                if (slots < 0) { valid = false; break; }
                if (!node.equals("#")) slots += 2;
            }
            if (slots != 0) valid = false;
            System.out.println(valid ? "true" : "false");
        }
    }
}