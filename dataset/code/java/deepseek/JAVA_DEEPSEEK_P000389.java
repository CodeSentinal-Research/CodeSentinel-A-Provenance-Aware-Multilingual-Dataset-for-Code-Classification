import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Employee {
    String name;
    String department;

    Employee(String name, String department) {
        this.name = name;
        this.department = department;
    }

    @Override
    public String toString() {
        return name + " " + department;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Employee> employees = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            employees.add(new Employee(input[0], input[1]));
        }
        String department = br.readLine();
        boolean found = false;
        for (Employee e : employees) {
            if (e.department.equals(department)) {
                System.out.println(e);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No Records Found");
        }
    }
}
