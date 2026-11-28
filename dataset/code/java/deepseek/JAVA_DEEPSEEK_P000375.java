import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static class Patient {
        String name;
        int age;

        Patient(String name, int age) {
            this.name = name;
            this.age = age;
        }

        @Override
        public String toString() {
            return "Name: " + name + ", Age: " + age;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Patient> patients = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String[] record = br.readLine().split(" ");
            patients.put(record[0], new Patient(record[1], Integer.parseInt(record[2])));
        }

        String id = br.readLine();
        Patient patient = patients.get(id);

        if (patient == null) {
            System.out.println("Patient Not Found");
        } else {
            System.out.println(patient);
        }
    }
}
