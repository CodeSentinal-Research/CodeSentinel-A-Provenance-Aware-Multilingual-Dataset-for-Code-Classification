import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] files = new String[n];
            for (int i = 0; i < n; i++) files[i] = scanner.next();
            String ext = scanner.next();
            if (!ext.startsWith(".")) ext = "." + ext;
            for (String f : files) {
                if (f.endsWith(ext)) {
                    System.out.println(f);
                }
            }
        }
    }
}