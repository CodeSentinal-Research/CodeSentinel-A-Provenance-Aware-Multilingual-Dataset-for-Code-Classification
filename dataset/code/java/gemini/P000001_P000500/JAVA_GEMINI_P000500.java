import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int depth = 0;
            for (int i = 0; i < n; i++) {
                String op = scanner.next();
                if (op.equals("../")) {
                    if (depth > 0) depth--;
                } else if (op.equals("./")) {
                } else {
                    depth++;
                }
            }
            System.out.println(depth);
        }
    }
}