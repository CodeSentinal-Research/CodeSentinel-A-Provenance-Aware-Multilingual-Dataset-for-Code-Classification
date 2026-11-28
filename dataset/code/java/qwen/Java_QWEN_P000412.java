import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<String, String> contacts = new LinkedHashMap<>();
        for(int i=0; i<n; i++) {
            String name = sc.next();
            String phone = sc.next();
            contacts.put(name.toLowerCase(), phone);
        }
        String searchName = sc.next().toLowerCase();
        if(contacts.containsKey(searchName)) System.out.println(contacts.get(searchName));
        else System.out.println("Contact Not Found");
    }
}
