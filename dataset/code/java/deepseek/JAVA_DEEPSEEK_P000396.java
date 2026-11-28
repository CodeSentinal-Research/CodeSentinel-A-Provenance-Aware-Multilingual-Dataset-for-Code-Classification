import java.io.*;
import java.util.*;

public class Main {
    public static class User {
        String name;
        boolean isActive;

        User(String name, boolean isActive) {
            this.name = name;
            this.isActive = isActive;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<User> users = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] data = br.readLine().split(" ");
            users.add(new User(data[0], data[1].equals("active")));
        }

        List<String> activeUsers = new ArrayList<>();
        for (User user : users) {
            if (user.isActive) {
                activeUsers.add(user.name);
            }
        }

        System.out.println(String.join("\n", activeUsers));
    }
}
