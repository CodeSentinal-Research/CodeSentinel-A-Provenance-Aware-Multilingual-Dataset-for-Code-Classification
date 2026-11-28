import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            String rev = new StringBuilder(s).reverse().toString();
            System.out.println(s.equals(rev) ? "Palindrome" : "Not Palindrome");
        }
    }
}