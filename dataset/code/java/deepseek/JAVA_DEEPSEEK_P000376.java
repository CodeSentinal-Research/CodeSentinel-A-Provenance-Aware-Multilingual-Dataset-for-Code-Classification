import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String, String> customers = new HashMap<>();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String mobile = st.nextToken();
            customers.put(mobile, name);
        }

        String mobile = br.readLine();
        String name = customers.get(mobile);
        if (name == null) {
            System.out.println("Customer Not Found");
        } else {
            System.out.println(name);
        }
    }
}
