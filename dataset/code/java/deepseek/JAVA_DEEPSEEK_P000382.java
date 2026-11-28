import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        Map<String, String> userMap = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] userData = reader.readLine().split(" ");
            userMap.put(userData[0], userData[1]);
        }
        String username = reader.readLine();
        System.out.println(userMap.getOrDefault(username, "User Not Found"));
    }
}
