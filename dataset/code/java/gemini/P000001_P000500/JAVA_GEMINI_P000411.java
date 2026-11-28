import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            int n = Integer.parseInt(scanner.nextLine().trim());
            String[] records = new String[n];
            for (int i = 0; i < n; i++) records[i] = scanner.nextLine();
            String keyword = scanner.nextLine().trim();
            for (String r : records) if (r.contains(keyword)) System.out.println(r);
        }
    }
}