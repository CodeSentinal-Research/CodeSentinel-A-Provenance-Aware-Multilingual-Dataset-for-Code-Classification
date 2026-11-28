import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            char c = scanner.next().charAt(0);
            System.out.println(s.indexOf(c));
        }
    }
}