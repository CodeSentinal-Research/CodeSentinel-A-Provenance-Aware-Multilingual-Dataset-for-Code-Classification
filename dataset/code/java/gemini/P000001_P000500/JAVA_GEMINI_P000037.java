import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String b = scanner.next();
            System.out.println(Integer.parseInt(b, 2));
        }
    }
}