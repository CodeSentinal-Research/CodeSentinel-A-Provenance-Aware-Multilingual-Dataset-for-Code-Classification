import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        generatePermutations(s, 0);
    }

    private static void generatePermutations(String s, int index) {
        if (index == s.length()) {
            System.out.println(s);
            return;
        }

        char[] chars = s.toCharArray();
        if (Character.isLetter(chars[index])) {
            chars[index] = Character.toLowerCase(chars[index]);
            generatePermutations(new String(chars), index + 1);

            chars[index] = Character.toUpperCase(chars[index]);
            generatePermutations(new String(chars), index + 1);
        } else {
            generatePermutations(s, index + 1);
        }
    }
}
