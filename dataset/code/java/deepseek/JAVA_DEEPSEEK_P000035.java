import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int sum = 0;
        for(int i = 1; i <= n/2; i++) {
            if(n % i == 0) {
                sum += i;
            }
        }
        if(sum == n) {
            System.out.println("Perfect");
        } else {
            System.out.println("Not Perfect");
        }
    }
}
