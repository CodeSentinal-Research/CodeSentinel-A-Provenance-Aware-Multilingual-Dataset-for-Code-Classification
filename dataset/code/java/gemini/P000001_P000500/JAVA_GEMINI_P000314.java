import java.util.*;

public class Solution {
    public static String convertToTitle(long columnNumber) {
        StringBuilder sb = new StringBuilder();
        while (columnNumber > 0) {
            columnNumber--;
            sb.append((char)('A' + (columnNumber % 26)));
            columnNumber /= 26;
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLong()) {
            System.out.println(convertToTitle(scanner.nextLong()));
        }
    }
}