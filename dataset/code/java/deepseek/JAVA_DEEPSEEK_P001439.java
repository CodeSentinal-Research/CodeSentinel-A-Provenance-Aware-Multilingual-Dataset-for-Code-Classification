import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<String> set = new HashSet<>();
        while (n-- > 0) {
            String word = scanner.next();
            set.add(word);
        }
        System.out.println(set.size());
    }
}
