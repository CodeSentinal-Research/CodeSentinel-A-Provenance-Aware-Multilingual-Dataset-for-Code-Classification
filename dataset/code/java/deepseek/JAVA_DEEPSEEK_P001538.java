import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s1 = scanner.nextLine();
        String s2 = scanner.nextLine();

        if (s1.length() > s2.length()) {
            System.out.println("NO");
            return;
        }

        int[] count1 = new int[26];
        int[] count2 = new int[26];

        for (int i = 0; i < s1.length(); i++) {
            count1[s1.charAt(i) - 'a']++;
        }

        for (int i = 0; i < s2.length() - s1.length() + 1; i++) {
            count2[s2.charAt(i) - 'a']++;
        }

        if (compareCounts(count1, count2)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean compareCounts(int[] count1, int[] count2) {
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }
        return true;
    }
}
