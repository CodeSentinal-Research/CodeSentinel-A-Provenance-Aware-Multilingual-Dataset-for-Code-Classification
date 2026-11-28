import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String binary = scanner.nextLine();
        System.out.println(countSubarrays(binary, n));
    }

    public static long countSubarrays(String binary, int n) {
        long count = 0;
        int zeroCount = 0, oneCount = 0;
        for (int i = 0; i < n; i++) {
            if (binary.charAt(i) == '0') {
                zeroCount++;
            } else {
                oneCount++;
            }
            if (zeroCount == oneCount) {
                count += zeroCount;
            }
        }
        return count;
    }
}
