import java.io.*;
import java.util.*;

public class Main {
    static class Contact {
        String name;
        String number;

        Contact(String name, String number) {
            this.name = name;
            this.number = number;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Contact[] contacts = new Contact[n];
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            contacts[i] = new Contact(input[0], input[1]);
        }
        String name = br.readLine();
        boolean found = false;
        for (Contact contact : contacts) {
            if (contact.name.equals(name)) {
                System.out.println(contact.name + " " + contact.number);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Contact Not Found");
        }
    }
}
