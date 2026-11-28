import java.io.*;
import java.util.*;

public class Main {
    public static class Employee {
        String name;
        String department;
        boolean isActive;

        Employee(String name, String department, boolean isActive) {
            this.name = name;
            this.department = department;
            this.isActive = isActive;
        }

        @Override
        public String toString() {
            return "Employee{" +
                    "name='" + name + '\'' +
                    ", department='" + department + '\'' +
                    ", isActive=" + isActive +
                    '}';
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Employee> employees = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(",");
            employees.add(new Employee(parts[0], parts[1], parts[2].equals("active")));
        }
        String targetDepartment = br.readLine();
        for (Employee e : employees) {
            if (e.department.equals(targetDepartment) && e.isActive) {
                System.out.println(e);
            }
        }
    }
}
