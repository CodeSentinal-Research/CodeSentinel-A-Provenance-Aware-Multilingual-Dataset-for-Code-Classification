import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            if (s.equals("-1")) System.out.println(0);
            else System.out.println(s);
        } else {
            System.out.println(0);
        }
    }
}