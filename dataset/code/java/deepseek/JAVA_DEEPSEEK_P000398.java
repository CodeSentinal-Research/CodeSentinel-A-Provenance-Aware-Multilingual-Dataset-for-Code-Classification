import java.io.*;
import java.util.*;

public class Main {
    static class Vehicle {
        String manufacturer;
        String model;
        int year;

        Vehicle(String manufacturer, String model, int year) {
            this.manufacturer = manufacturer;
            this.model = model;
            this.year = year;
        }

        @Override
        public String toString() {
            return manufacturer + " " + model + " " + year;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Vehicle> vehicles = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] parts = br.readLine().split(" ");
            vehicles.add(new Vehicle(parts[0], parts[1], Integer.parseInt(parts[2])));
        }
        String manufacturer = br.readLine();
        for (Vehicle vehicle : vehicles) {
            if (vehicle.manufacturer.equals(manufacturer)) {
                System.out.println(vehicle);
            }
        }
    }
}
