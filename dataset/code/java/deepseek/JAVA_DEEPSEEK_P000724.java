import java.util.*;

public class Main {
    private static int maxLength(Set<String> dict) {
        if (dict.isEmpty()) {
            return 0;
        }
        String s = dict.iterator().next();
        dict.remove(s);
        Set<String> newDict = new HashSet<>(dict);
        for (int i = 0; i < s.length(); i++) {
            String suffix = s.substring(i);
            if (newDict.contains(suffix)) {
                newDict.remove(suffix);
                int withSuffix = 1 + maxLength(newDict);
                newDict.add(suffix);
                int withoutSuffix = maxLength(newDict);
                return Math.max(withSuffix, withoutSuffix);
            }
        }
        dict.add(s);
        return maxLength(newDict);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<String> words = new HashSet<>();
        for (int i = 0; i < n; i++) {
            words.add(scanner.next());
        }
        System.out.println(maxLength(words));
    }
}
