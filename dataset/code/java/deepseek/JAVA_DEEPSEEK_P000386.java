import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static class Account {
        String name;
        String email;

        Account(String name, String email) {
            this.name = name;
            this.email = email;
        }

        @Override
        public String toString() {
            return name + " " + email;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        Map<String, Account> accounts = new HashMap<>();
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String email = st.nextToken();
            String accountNumber = st.nextToken();
            accounts.put(accountNumber, new Account(name, email));
        }
        String accountNumberToFind = br.readLine();
        Account account = accounts.get(accountNumberToFind);
        if (account == null) {
            System.out.println("Account Not Found");
        } else {
            System.out.println(account);
        }
    }
}
