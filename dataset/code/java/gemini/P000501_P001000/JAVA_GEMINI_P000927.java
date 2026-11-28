import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNext()) {
            String s = sc.next();
            int b1 = sc.nextInt();
            int b2 = sc.nextInt();
            long val = Long.parseLong(s, b1);
            System.out.println(Long.toString(val, b2).toUpperCase());
        }
        sc.close();
    }
}