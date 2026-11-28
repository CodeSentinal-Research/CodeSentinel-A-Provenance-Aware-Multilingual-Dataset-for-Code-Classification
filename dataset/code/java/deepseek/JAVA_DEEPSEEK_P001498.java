import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String binaryString = scanner.nextLine();
        int left = 0;
        int right = binaryString.length() - 1;
        int swapCount = 0;

        while (left < right) {
            while (left < right && binaryString.charAt(left) == '0') {
                left++;
            }

            while (left < right && binaryString.charAt(right) == '1') {
                right--;
            }

            if (binaryString.charAt(left) == '0' && binaryString.charAt(right) == '1') {
                binaryString = swapBalls(binaryString, left, right);
                swapCount++;
            }
        }

        System.out.println(swapCount);
    }

    private static String swapBalls(String binaryString, int left, int right) {
        char[] chars = binaryString.toCharArray();
        char temp = chars[left];
        chars[left] = chars[right];
        chars[right] = temp;
        return String.valueOf(chars);
    }
}
