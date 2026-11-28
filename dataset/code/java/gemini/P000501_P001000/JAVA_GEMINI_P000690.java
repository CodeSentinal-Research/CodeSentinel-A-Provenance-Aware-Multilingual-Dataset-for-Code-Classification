import java.util.*;
public class Solution {
    static String decToBin(long n) {
        if (n == 0) return "0";
        if (n == 1) return "1";
        return decToBin(n / 2) + (n % 2);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            System.out.println(decToBin(scanner.nextLong()));
        }
    }
}