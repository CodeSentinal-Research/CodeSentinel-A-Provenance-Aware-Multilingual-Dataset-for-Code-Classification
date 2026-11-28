import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int mid = s.length() / 2;
        String firstHalf = s.substring(0, mid);
        String secondHalf = s.substring(mid);
        int firstHalfVowels = countVowels(firstHalf);
        int secondHalfVowels = countVowels(secondHalf);
        System.out.println(firstHalfVowels == secondHalfVowels ? "Yes" : "No");
    }

    private static int countVowels(String s) {
        int count = 0;
        for (char c : s.toCharArray()) {
            if ("AEIOUaeiou".indexOf(c) != -1) {
                count++;
           }
        }
        return count;
    }
}
