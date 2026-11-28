import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            if (s.equals("-1")) System.out.println("false");
            else System.out.println("true");
        } else {
            System.out.println("false");
        }
    }
}