import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String source = scanner.next();
        String target = scanner.next();
        System.out.println(shortestWay(source, target));
    }

    private static int shortestWay(String source, String target) {
        int[] count = new int[26];
        for (char c : source.toCharArray()) {
            count[c - 'a']++;
        }
        int subsequences = 0;
        for (char c : target.toCharArray()) {
            if (count[c - 'a'] > 0) {
                count[c - 'a']--;
           
            } else {
                subsequences++;
                for (char sc : source.toCharArray()) {
                    count[sc - 'a']++;
                }
                count[c - 'a']--;
            }
        }
        return subsequences;
    }
}
