import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static class Flight {
        String flightNumber;
        String destination;

        public Flight(String flightNumber, String destination) {
            this.flightNumber = flightNumber;
            this.destination = destination;
        }

        public String getFlightNumber() {
            return flightNumber;
        }

        public String getDestination() {
            return destination;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Flight> flights = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String[] flightDetails = br.readLine().split(" ");
            flights.add(new Flight(flightDetails[0], flightDetails[1]));
        }
        String destination = br.readLine();
        for (Flight flight : flights) {
            if (flight.getDestination().equals(destination)) {
                System.out.println(flight.getFlightNumber() + " " + flight.getDestination());
            }
        }
    }
}
