import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String binary = scanner.nextLine();
        System.out.println(minSwaps(binary));
    }

    public static int minSwaps(String binary) {
        int swapCount = 0;
        int lastSwap = 0;
        for (int i = 0; i < binary.length(); i++) {
            if (binary.charAt(i) == '1') {
                if (i != lastSwap) {
                    swapCount++;
                    lastSwap = swap(binary, i);
                }
            }
        }
        return swapCount;
    }

    public static int swap(String binary, int index) {
        for (int i = index; i < binary.length(); i++) {
            if (binary.charAt(i) == '1') {
                return i;
            }
        }
        return binary.length();
    }
}
