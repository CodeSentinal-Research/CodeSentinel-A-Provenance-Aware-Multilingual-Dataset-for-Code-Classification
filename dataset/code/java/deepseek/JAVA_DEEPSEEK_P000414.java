import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int budget = scanner.nextInt();
        scanner.nextLine();

        List<Flight> flights = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] flightDetails = scanner.nextLine().split(" ");
            String flightNumber = flightDetails[0];
            int price = Integer.parseInt(flightDetails[1]);
            flights.add(new Flight(flightNumber, price));
        }

        flights.stream()
                .filter(f -> f.price <= budget)
                .forEach(f -> System.out.println(f.flightNumber));
    }

    static class Flight {
        String flightNumber;
        int price;

        Flight(String flightNumber, int price) {
            this.flightNumber = flightNumber;
            this.price = price;
        }
    }
}
