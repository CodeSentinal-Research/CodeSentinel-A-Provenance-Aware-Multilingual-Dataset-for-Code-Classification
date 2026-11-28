import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        scanner.nextLine();

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            String source = scanner.next();
            String destination = scanner.next();
            map.put(source, destination);
        }

        for (String city : map.keySet()) {
            if (!map.containsValue(city)) {
                System.out.println(city);
                break;
            }
        }
    }
}
