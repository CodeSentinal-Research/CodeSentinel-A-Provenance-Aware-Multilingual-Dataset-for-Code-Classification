import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        long a = countSubstrings(s, 'a');
        long b = countSubstrings(s, 'b');
        long c = countSubstrings(s, 'c');
        long total = a * b * c;
        System.out.println(total);
    }

    private static long countSubstrings(String s, char c) {
        long count = 0;
        int lastIndex = -1;
        while (true) {
            int index = s.indexOf(c, lastIndex + 1);
            if (index == -1) {
                break;
            }
            count += index - lastIndex;
            lastIndex = index;
        }
        return count;
    }
}
