import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.*;

class HotelReservationSystem {

    public static class Room {
        private String roomNumber;
        private RoomType type;
        private double pricePerNight;
        private String description;

        public Room(String roomNumber, RoomType type, double pricePerNight, String description) {
            this.roomNumber = roomNumber;
            this.type = type;
            this.pricePerNight = pricePerNight;
            this.description = description;
        }

        public String getRoomNumber() {
            return roomNumber;
        }

        public RoomType getType() {
            return type;
        }

        public double getPricePerNight() {
            return pricePerNight;
        }

        public String getDescription() {
            return description;
        }

        @Override
        public String toString() {
            return String.format("Room: %s (%s) - %.2f/night. %s",
                    roomNumber, type.getName(), pricePerNight, description);
        }
    }

    enum RoomType {
        SINGLE("Single", 1),
        DOUBLE("Double", 2),
        SUITE("Suite", 4);

        private final String name;
        private final int maxOccupancy;

        RoomType(String name, int maxOccupancy) {
            this.name = name;
            this.maxOccupancy = maxOccupancy;
        }

        public String getName() {
            return name;
        }

        public int getMaxOccupancy() {
            return maxOccupancy;
        }
    }

    public static class Booking {
        private String bookingId;
        private Room room;
        private LocalDate checkInDate;
        private LocalDate checkOutDate;
        private String guestName;
        private String guestEmail;
        private double totalPrice;
        private BookingStatus status;

        enum BookingStatus {
            PENDING, CONFIRMED, CANCELLED
        }

        public Booking(String bookingId, Room room, LocalDate checkInDate, LocalDate checkOutDate, String guestName, String guestEmail, double totalPrice) {
            this.bookingId = bookingId;
            this.room = room;
            this.checkInDate = checkInDate;
            this.checkOutDate = checkOutDate;
            this.guestName = guestName;
            this.guestEmail = guestEmail;
            this.totalPrice = totalPrice;
            this.status = BookingStatus.PENDING;
        }

        public String getBookingId() {
            return bookingId;
        }

        public Room getRoom() {
            return room;
        }

        public LocalDate getCheckInDate() {
            return checkInDate;
        }

        public LocalDate getCheckOutDate() {
            return checkOutDate;
        }

        public String getGuestName() {
            return guestName;
        }

        public String getGuestEmail() {
            return guestEmail;
        }

        public double getTotalPrice() {
            return totalPrice;
        }

        public BookingStatus getStatus() {
            return status;
        }

        public void setStatus(BookingStatus status) {
            this.status = status;
        }

        @Override
        public String toString() {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
            return String.format("Booking ID: %s\n  Room: %s (%s)\n  Dates: %s to %s\n  Guest: %s (%s)\n  Total Price: %.2f\n  Status: %s\n",
                    bookingId, room.getRoomNumber(), room.getType().getName(),
                    checkInDate.format(formatter), checkOutDate.format(formatter),
                    guestName, guestEmail, totalPrice, status);
        }
    }

    public static class Hotel {
        private Map<String, Room> rooms;
        private List<Booking> bookings;
        private Random random;

        public Hotel() {
            this.rooms = new HashMap<>();
            this.bookings = new ArrayList<>();
            this.random = new Random();
            initializeRooms();
        }

        private void initializeRooms() {
            rooms.put("101", new Room("101", RoomType.SINGLE, 50.00, "Cozy single bed room"));
            rooms.put("102", new Room("102", RoomType.SINGLE, 50.00, "Cozy single bed room"));
            rooms.put("201", new Room("201", RoomType.DOUBLE, 80.00, "Spacious double bed room"));
            rooms.put("202", new Room("202", RoomType.DOUBLE, 80.00, "Spacious double bed room with city view"));
            rooms.put("301", new Room("301", RoomType.SUITE, 150.00, "Luxury suite with separate living area"));
            rooms.put("302", new Room("302", RoomType.SUITE, 150.00, "Executive suite with balcony"));
        }

        public List<Room> searchAvailableRooms(LocalDate checkIn, LocalDate checkOut, RoomType desiredType) {
            List<Room> availableRooms = new ArrayList<>();
            for (Room room : rooms.values()) {
                if (room.getType() == desiredType) {
                    boolean isBooked = false;
                    for (Booking booking : bookings) {
                        if ((booking.getStatus() == Booking.BookingStatus.CONFIRMED || booking.getStatus() == Booking.BookingStatus.PENDING) &&
                            booking.getRoom().equals(room) &&
                            !(checkOut.isBefore(booking.getCheckInDate()) || checkIn.isAfter(booking.getCheckOutDate().minusDays(1)))) {
                            isBooked = true;
                            break;
                        }
                    }
                    if (!isBooked) {
                        availableRooms.add(room);
                    }
                }
            }
            return availableRooms;
        }

        public Booking createBooking(Room room, LocalDate checkIn, LocalDate checkOut, String guestName, String guestEmail) {
            long numOfNights = java.time.temporal.ChronoUnit.DAYS.between(checkIn, checkOut);
            if (numOfNights <= 0) {
                System.out.println("Invalid dates. Check-out date must be after check-in date.");
                return null;
            }
            double totalPrice = room.getPricePerNight() * numOfNights;
            String bookingId = "BOOK" + (random.nextInt(9000) + 1000);
            Booking newBooking = new Booking(bookingId, room, checkIn, checkOut, guestName, guestEmail, totalPrice);
            bookings.add(newBooking);
            return newBooking;
        }

        public Booking findBooking(String bookingId) {
            for (Booking booking : bookings) {
                if (booking.getBookingId().equalsIgnoreCase(bookingId)) {
                    return booking;
                }
            }
            return null;
        }

        public List<Booking> getAllBookings() {
            return new ArrayList<>(bookings);
        }
    }

    public static class PaymentProcessor {
        public boolean processPayment(Booking booking, double amount, String paymentMethod) {
            System.out.println("\nProcessing payment for Booking ID: " + booking.getBookingId());
            System.out.printf("Amount: %.2f via %s\n", amount, paymentMethod);
            if (amount >= booking.getTotalPrice()) {
                System.out.println("Payment successful! Booking confirmed.");
                booking.setStatus(Booking.BookingStatus.CONFIRMED);
                return true;
            } else {
                System.out.println("Payment failed: Insufficient amount.");
                booking.setStatus(Booking.BookingStatus.PENDING);
                return false;
            }
        }
    }

    private Hotel hotel;
    private PaymentProcessor paymentProcessor;
    private Scanner scanner;
    private DateTimeFormatter dateFormatter;

    public HotelReservationSystem() {
        this.hotel = new Hotel();
        this.paymentProcessor = new PaymentProcessor();
        this.scanner = new Scanner(System.in);
        this.dateFormatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        System.out.println("Welcome to the Hotel Reservation System!");
    }

    public void start() {
        int choice;
        do {
            displayMenu();
            System.out.print("Enter your choice: ");
            choice = getUserIntInput();

            switch (choice) {
                case 1:
                    searchAndBookRoom();
                    break;
                case 2:
                    viewBookingDetails();
                    break;
                case 3:
                    System.out.println("Feature not implemented in this simplified version.");
                    break;
                case 4:
                    viewAllBookings();
                    break;
                case 5:
                    System.out.println("Thank you for using our system. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
            System.out.println();
        } while (choice != 5);

        scanner.close();
    }

    private void displayMenu() {
        System.out.println("\n--- Main Menu ---");
        System.out.println("1. Search & Book a Room");
        System.out.println("2. View Booking Details (by ID)");
        System.out.println("3. Manage My Bookings (Cancel/Modify - Not fully implemented)");
        System.out.println("4. View All Bookings (Admin View)");
        System.out.println("5. Exit");
    }

    private int getUserIntInput() {
        while (!scanner.hasNextInt()) {
            System.out.println("Invalid input. Please enter a number.");
            scanner.next();
            System.out.print("Enter your choice: ");
        }
        int input = scanner.nextInt();
        scanner.nextLine();
        return input;
    }

    private double getUserDoubleInput() {
        while (!scanner.hasNextDouble()) {
            System.out.println("Invalid input. Please enter a number.");
            scanner.next();
            System.out.print("Enter amount: ");
        }
        double input = scanner.nextDouble();
        scanner.nextLine();
        return input;
    }

    private void searchAndBookRoom() {
        System.out.println("\n--- Search & Book Room ---");
        LocalDate checkIn = null;
        LocalDate checkOut = null;
        RoomType desiredType = null;

        while (checkIn == null) {
            System.out.print("Enter Check-in Date (DD-MM-YYYY): ");
            String dateStr = scanner.nextLine();
            try {
                checkIn = LocalDate.parse(dateStr, dateFormatter);
                if (checkIn.isBefore(LocalDate.now())) {
                    System.out.println("Check-in date cannot be in the past. Please try again.");
                    checkIn = null;
                }
            } catch (DateTimeParseException e) {
                System.out.println("Invalid date format. Please use DD-MM-YYYY.");
            }
        }

        while (checkOut == null) {
            System.out.print("Enter Check-out Date (DD-MM-YYYY): ");
            String dateStr = scanner.nextLine();
            try {
                checkOut = LocalDate.parse(dateStr, dateFormatter);
                if (checkOut.isBefore(checkIn.plusDays(1))) {
                    System.out.println("Check-out date must be at least one day after check-in date. Please try again.");
                    checkOut = null;
                }
            } catch (DateTimeParseException e) {
                System.out.println("Invalid date format. Please use DD-MM-YYYY.");
            }
        }

        System.out.println("Available Room Types:");
        for (RoomType type : RoomType.values()) {
            System.out.println("- " + type.getName() + " (Max Occupancy: " + type.getMaxOccupancy() + ")");
        }

        while (desiredType == null) {
            System.out.print("Enter desired Room Type (Single, Double, Suite): ");
            String typeStr = scanner.nextLine().toUpperCase();
            try {
                desiredType = RoomType.valueOf(typeStr);
            } catch (IllegalArgumentException e) {
                System.out.println("Invalid room type. Please choose from Single, Double, Suite.");
            }
        }

        List<Room> availableRooms = hotel.searchAvailableRooms(checkIn, checkOut, desiredType);

        if (availableRooms.isEmpty()) {
            System.out.println("No " + desiredType.getName() + " rooms available for the selected dates.");
            return;
        }

        System.out.println("\n--- Available " + desiredType.getName() + " Rooms ---");
        for (int i = 0; i < availableRooms.size(); i++) {
            System.out.println((i + 1) + ". " + availableRooms.get(i));
        }

        System.out.print("Enter the number of the room you want to book (or 0 to cancel): ");
        int roomChoice = getUserIntInput();

        if (roomChoice == 0) {
            System.out.println("Booking cancelled.");
            return;
        }

        if (roomChoice < 1 || roomChoice > availableRooms.size()) {
            System.out.println("Invalid room selection.");
            return;
        }

        Room selectedRoom = availableRooms.get(roomChoice - 1);

        System.out.print("Enter your Name: ");
        String guestName = scanner.nextLine();
        System.out.print("Enter your Email: ");
        String guestEmail = scanner.nextLine();

        Booking newBooking = hotel.createBooking(selectedRoom, checkIn, checkOut, guestName, guestEmail);

        if (newBooking != null) {
            System.out.println("\n--- Booking Summary ---");
            System.out.println(newBooking);
            System.out.print("Proceed to payment? (yes/no): ");
            String paymentConfirm = scanner.nextLine().toLowerCase();

            if (paymentConfirm.equals("yes")) {
                System.out.print("Enter payment amount: ");
                double paymentAmount = getUserDoubleInput();
                System.out.print("Enter payment method (e.g., Card, UPI): ");
                String paymentMethod = scanner.nextLine();

                if (paymentProcessor.processPayment(newBooking, paymentAmount, paymentMethod)) {
                    System.out.println("Booking " + newBooking.getBookingId() + " has been CONFIRMED!");
                } else {
                    System.out.println("Payment failed. Booking " + newBooking.getBookingId() + " remains PENDING.");
                }
            } else {
                System.out.println("Payment skipped. Booking " + newBooking.getBookingId() + " remains PENDING.");
            }
        } else {
            System.out.println("Failed to create booking.");
        }
    }

    private void viewBookingDetails() {
        System.out.println("\n--- View Booking Details ---");
        System.out.print("Enter Booking ID: ");
        String bookingId = scanner.nextLine();

        Booking booking = hotel.findBooking(bookingId);
        if (booking != null) {
            System.out.println(booking);
            if (booking.getStatus() == Booking.BookingStatus.PENDING) {
                System.out.print("Would you like to complete payment for this booking? (yes/no): ");
                String confirmPayment = scanner.nextLine().toLowerCase();
                if (confirmPayment.equals("yes")) {
                    System.out.print("Enter payment amount: ");
                    double paymentAmount = getUserDoubleInput();
                    System.out.print("Enter payment method (e.g., Card, UPI): ");
                    String paymentMethod = scanner.nextLine();

                    if (paymentProcessor.processPayment(booking, paymentAmount, paymentMethod)) {
                        System.out.println("Booking " + booking.getBookingId() + " has been CONFIRMED!");
                    } else {
                        System.out.println("Payment failed. Booking " + booking.getBookingId() + " remains PENDING.");
                    }
                }
            }
        } else {
            System.out.println("Booking with ID '" + bookingId + "' not found.");
        }
    }

    private void viewAllBookings() {
        System.out.println("\n--- All Bookings (Admin View) ---");
        List<Booking> allBookings = hotel.getAllBookings();
        if (allBookings.isEmpty()) {
            System.out.println("No bookings have been made yet.");
        } else {
            for (Booking booking : allBookings) {
                System.out.println("-----------------------------------");
                System.out.println(booking);
            }
            System.out.println("-----------------------------------");
        }
    }

    public static void main(String[] args) {
        HotelReservationSystem system = new HotelReservationSystem();
        system.start();
    }
}
