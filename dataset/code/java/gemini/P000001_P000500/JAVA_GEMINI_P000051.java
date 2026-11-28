import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            char c = scanner.next().charAt(0);
            System.out.println(Character.isUpperCase(c) ? "Uppercase" : "Lowercase");
        }
    }
}