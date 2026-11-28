import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            String line1 = scanner.nextLine();
            String line2 = scanner.hasNextLine() ? scanner.nextLine() : "";
            String s1 = String.join("", line1.trim().split("\\s+"));
            String s2 = String.join("", line2.trim().split("\\s+"));
            System.out.println(s1.equals(s2) ? "Yes" : "No");
        }
    }
}