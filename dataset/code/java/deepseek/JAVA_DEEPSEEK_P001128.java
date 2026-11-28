import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        Map<String, List<String>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            String email = scanner.next();
            map.putIfAbsent(name, new ArrayList<>());
            map.get(name).add(email);
        }

        for (Map.Entry<String, List<String>> entry : map.entrySet()) {
            List<String> emails = entry.getValue();
            Collections.sort(emails);
            System.out.println(entry.getKey() + " " + String.join(";", emails));
        }
    }
}
