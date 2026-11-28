import java.io.*;
import java.util.*;

public class Main {
    static class Passport {
        String name;
        String passportNumber;

        Passport(String name, String passportNumber) {
            this.name = name;
            this.passportNumber = passportNumber;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Passport> passports = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            passports.add(new Passport(input[0], input[1]));
        }
        String passportNumberToFind = br.readLine();
        boolean found = false;
        for (Passport passport : passports) {
            if (passport.passportNumber.equals(passportNumberToFind)) {
                System.out.println(passport.name + " " + passport.passportNumber);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Passport Not Found");
        }
    }
}
