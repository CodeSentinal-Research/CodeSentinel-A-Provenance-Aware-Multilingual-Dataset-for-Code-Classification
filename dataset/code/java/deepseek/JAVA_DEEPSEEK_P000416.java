import java.util.*;

public class Main {
    public static class Vehicle {
        String make;
        String model;
        int year;

        public Vehicle(String make, String model, int year) {
            this.make = make;
            this.model = model;
            this.year = year;
        }

        public String toString() {
            return make + " " + model + " " + year;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int year = scanner.nextInt();
        scanner.nextLine();

        List<Vehicle> vehicles = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String make = scanner.next();
            String model = scanner.next();
            int vehicleYear = scanner.nextInt();
            if (vehicleYear > year) {
                vehicles.add(new Vehicle(make, model, vehicleYear));
            }
        }

        for (Vehicle vehicle : vehicles) {
            System.out.println(vehicle);
        }
    }
}
