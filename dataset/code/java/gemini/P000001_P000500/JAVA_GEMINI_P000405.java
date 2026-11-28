import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] c = new String[n], inst = new String[n];
            for (int i = 0; i < n; i++) { c[i] = scanner.next(); inst[i] = scanner.next(); }
            String target = scanner.next();
            for (int i = 0; i < n; i++) if (inst[i].equals(target)) System.out.println(c[i]);
        }
    }
}