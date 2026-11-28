import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<String> queries = Arrays.asList("helloWorld", "camelCase", "CamelCase", "camel_case");
        String pattern = "camelCase";
        List<Boolean> result = camelCaseMatching(queries, pattern);
        System.out.println(result);
    }

    public static List<Boolean> camelCaseMatching(List<String> queries, String pattern) {
        List<Boolean> result = new ArrayList<>();
        for (String query : queries) {
            result.add(match(query, pattern));
        }
        return result;
    }

    private static boolean match(String query, String pattern) {
        int i = 0, j = 0;
        while (i < query.length() && j < pattern.length()) {
            if (Character.isLowerCase(query.charAt(i))) {
                if (query.charAt(i) != pattern.charAt(j)) {
                    return false;
                }
                j++;
            } else {
                if (j == pattern.length() - 1 && i != query.length() - 1) {
                    return false;
                }
                if (query.charAt(i) != pattern.charAt(j)) {
                    return false;
                }
                j++;
            }
            i++;
        }
        while (i < query.length() && Character.isUpperCase(query.charAt(i))) {
            i++;
        }
        return i == query.length() && j == pattern.length();
    }
}
