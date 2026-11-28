import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        List<String> list1 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list1.add(scanner.next());
        }
        int m = scanner.nextInt();
        List<String> list2 = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            list2.add(scanner.next());
        }
        System.out.println(countWords(list1, list2));
    }

    private static int countWords(List<String> list1, List<String> list2) {
        int count = 0;
        for (String word : list2) {
            if (canBeFormed(list1, word)) {
                count++;
            }
        }
        return count;
    }

    private static boolean canBeFormed(List<String> list1, String word) {
        for (String str : list1) {
            if (str.length() != word.length()) {
                continue;
            }
            int diff = 0;
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) != word.charAt(i)) {
                    diff++;
                }
            }
            if (diff == 1) {
                return true;
            }
        }
        return false;
    }
}
