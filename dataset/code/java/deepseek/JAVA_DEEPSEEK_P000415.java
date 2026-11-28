import java.io.*;
import java.util.*;

class Patient {
    String name;
    String bloodGroup;

    Patient(String name, String bloodGroup) {
        this.name = name;
        this.bloodGroup = bloodGroup;
    }

    String getName() {
        return this.name;
    }

    String getBloodGroup() {
        return this.bloodGroup;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Patient> patients = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            patients.add(new Patient(input[0], input[1]));
        }
        String bloodGroup = br.readLine();
        for (Patient patient : patients) {
            if (patient.getBloodGroup().equals(bloodGroup)) {
                System.out.println(patient.getName());
            }
        }
    }
}
