import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int n = Integer.parseInt(s);
            int dSum = 0;
            for (char c : s.toCharArray()) if (Character.isDigit(c)) dSum += c - '0';
            System.out.println(dSum > 0 && n % dSum == 0 ? "Harshad" : "Not Harshad");
        }
    }
}