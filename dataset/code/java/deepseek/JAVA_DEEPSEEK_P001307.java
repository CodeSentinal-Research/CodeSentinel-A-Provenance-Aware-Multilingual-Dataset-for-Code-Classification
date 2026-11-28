import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        char[] street = scanner.next().toCharArray();
        int police = 0, thieves = 0, maxThieves = 0;

        for (int i = 0; i < N; i++) {
            if (street[i] == 'P') {
                police++;
            } else {
                thieves++;
                if (police > 0) {
                    maxThieves++;
                    police--;
                }
            }
        }

        System.out.println(maxThieves);
    }
}
