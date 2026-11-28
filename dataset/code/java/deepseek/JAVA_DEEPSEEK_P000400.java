import java.io.*;
import java.util.*;

public class Main {
    public static class Employee {
        String name;
        int salary;

        public Employee(String name, int salary) {
            this.name = name;
            this.salary = salary;
        }

        @Override
        public String toString() {
            return name + " " + salary;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Employee> employees = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            employees.add(new Employee(parts[0], Integer.parseInt(parts[1])));
        }
        String[] range = br.readLine().split(" ");
        int minSalary = Integer.parseInt(range[0]);
        int maxSalary = Integer.parseInt(range[1]);

        for (Employee employee : employees) {
            if (employee.salary >= minSalary && employee.salary <= maxSalary) {
                System.out.println(employee);
            }
        }
    }
}
