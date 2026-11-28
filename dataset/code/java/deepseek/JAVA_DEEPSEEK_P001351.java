import java.util.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static Set<String> set = new HashSet<>();
    static String str;
    static int k;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        str = sc.next();
        k = sc.nextInt();
        backtrack(0, "");
        set.stream().sorted().forEach(System.out::println);
    }

    public static void backtrack(int index, String str) {
        if (str.length() == k) {
            set.add(str);
            return;
        }
        for (int i = index; i < str.length(); i++) {
            backtrack(i + 1, str.substring(0, i + 1) + str.substring(i + 1, str.length()));
        }
    }
}
