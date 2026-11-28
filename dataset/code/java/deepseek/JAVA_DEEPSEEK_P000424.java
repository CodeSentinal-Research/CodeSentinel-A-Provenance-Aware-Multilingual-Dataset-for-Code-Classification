import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Map<String, Integer> emailCounts = new HashMap<>();

        while (scanner.hasNext()) {
            String email = scanner.next();
            emailCounts.put(email, emailCounts.getOrDefault(email, 0) + 1);
        }

        for (Map.Entry<String, Integer> entry : emailCounts.entrySet()) {
            if (entry.getValue() > 1) {
                System.out.println(entry.getKey());
            }
        }
    }
}
