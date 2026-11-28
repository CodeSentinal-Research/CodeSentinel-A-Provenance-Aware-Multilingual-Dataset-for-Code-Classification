import java.io.*;
import java.util.*;

class Employee {
    String id;
    String name;
    String department;

    Employee(String id, String name, String department) {
        this.id = id;
        this.name = name;
        this.department = department;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        Map<String, Employee> map = new HashMap<>();
        while (n-- > 0) {
            String[] input = br.readLine().split(" ");
            Employee emp = new Employee(input[0], input[1], input[2]);
            map.put(input[0], emp);
        }
        String id = br.readLine().trim();
        if (map.containsKey(id)) {
            Employee emp = map.get(id);
            System.out.println(emp.id + " " + emp.name + " " + emp.department);
        } else {
            System.out.println("Record Not Found");
        }
    }
}
