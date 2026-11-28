import java.io.*;
import java.util.*;
import java.time.*;

public class Main {
    public static class Employee {
        String name;
        LocalDate joinDate;

        public Employee(String name, LocalDate joinDate) {
            this.name = name;
            this.joinDate = joinDate;
        }

        public String toString() {
            return name + " " + joinDate;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Employee> employees = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            String name = parts[0];
            LocalDate joinDate = LocalDate.parse(parts[1]);
            employees.add(new Employee(name, joinDate));
        }
        LocalDate targetDate = LocalDate.parse(br.readLine());

        List<Employee> result = new ArrayList<>();
        for (Employee e : employees) {
            if (e.joinDate.isBefore(targetDate)) {
                result.add(e);
            }
        }

        for (Employee e : result) {
            System.out.println(e);
        }
    }
}
