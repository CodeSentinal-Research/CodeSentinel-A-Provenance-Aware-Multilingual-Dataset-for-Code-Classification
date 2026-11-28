import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long orig = N;
        long rev = 0;
        long temp = N;
        while (temp > 0) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        System.out.println(orig == rev ? "Palindrome" : "Not Palindrome");
    }
}
