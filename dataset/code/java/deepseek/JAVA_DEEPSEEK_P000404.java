import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static class Doctor {
        String name;
        String specialization;

        Doctor(String name, String specialization) {
            this.name = name;
            this.specialization = specialization;
        }

        void print() {
            System.out.println(name + " " + specialization);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Doctor[] doctors = new Doctor[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String specialization = st.nextToken();
            doctors[i] = new Doctor(name, specialization);
        }
        String targetSpecialization = br.readLine();
        for (Doctor doctor : doctors) {
            if (doctor.specialization.equals(targetSpecialization)) {
                doctor.print();
            }
        }
    }
}
