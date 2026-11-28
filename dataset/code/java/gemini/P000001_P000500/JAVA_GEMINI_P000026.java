import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            long n = Math.abs(scanner.nextLong());
            System.out.println(String.valueOf(n).length());
        }
    }
}