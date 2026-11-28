import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        generatePermutations(chars, 0);
    }

    private static void generatePermutations(char[] chars, int start) {
        if (start == chars.length - 1) {
            System.out.println(new String(chars));
        } else {
            for (int i = start; i < chars.length; i++) {
                swap(chars, start, i);
                generatePermutations(chars, start + 1);
                swap(chars, start, i);
            }
        }
    }

    private static void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }
}
