import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        List<String> usernames = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            usernames.add(scanner.nextLine());
        }
        String prefix = scanner.nextLine();
        for (String username : usernames) {
            if (username.startsWith(prefix)) {
                System.out.println(username);
            }
        }
    }
}
