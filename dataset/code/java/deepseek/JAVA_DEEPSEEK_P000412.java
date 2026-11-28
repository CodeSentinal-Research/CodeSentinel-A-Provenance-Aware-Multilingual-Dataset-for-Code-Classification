import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, List<String>> contacts = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            String name = input[0].toLowerCase();
            String number = input[1];
            if (!contacts.containsKey(name)) {
                contacts.put(name, new ArrayList<>());
            }
            contacts.get(name).add(number);
       
       }
       String search = br.readLine().toLowerCase();
       if (contacts.containsKey(search)) {
           List<String> numbers = contacts.get(search);
           for (String number : numbers) {
               System.out.println(search + " " + number);
           }
       }
    }
}
