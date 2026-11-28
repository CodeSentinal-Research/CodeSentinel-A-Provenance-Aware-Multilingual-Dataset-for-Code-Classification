import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        char[] characters = new char[n];
        for (int i = 0; i < n; i++) {
            characters[i] = scanner.next().charAt(0);
        }
        int k = scanner.nextInt();
        generateAllKLengthStrings(characters, k);
    }

    private static void generateAllKLengthStrings(char[] set, int k) {
        char[] str = new char[k];
        generateAllKLengthStringsRecursive(set, k, str, 0);
    }

    private static void generateAllKLengthStringsRecursive(char[] set, int k, char[] str, int level) {
        if (level == k) {
            System.out.println(str);
            return;
        }

        for (int i = 0; i < set.length; i++) {
            str[level] = set[i];
            generateAllKLengthStringsRecursive(set, k, str, level + 1);
        }
    }
}
