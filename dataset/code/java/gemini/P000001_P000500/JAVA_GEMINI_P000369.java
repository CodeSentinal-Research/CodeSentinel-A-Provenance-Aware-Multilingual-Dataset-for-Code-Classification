import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            int n = Integer.parseInt(scanner.nextLine().trim());
            int idx = -1;
            for (int i = 0; i < n; i++) {
                String line = scanner.nextLine();
                if (line.isEmpty() && idx == -1) idx = i;
            }
            System.out.println(idx);
        }
    }
}