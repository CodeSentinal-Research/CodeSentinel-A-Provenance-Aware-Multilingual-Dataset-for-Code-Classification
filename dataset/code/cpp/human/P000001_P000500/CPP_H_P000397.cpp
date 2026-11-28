// ============================================================
//  E-COMMERCE ENGINE  —  C++ Class Template
// ============================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>

using namespace std;

// ─────────────────────────────────────────────
//  1. PRODUCT
// ─────────────────────────────────────────────
class Product {
public:
    int         id;
    string name;
    double      price;
    int         stock;
    string category;

    Product(int id, const string& name, double price,
            int stock, const string& category)
        : id(id), name(name), price(price),
          stock(stock), category(category) {}

    // Apply a percentage discount (0-100) to price
    void applyDiscount(double percent) {
        price = price - (price * percent / 100);
    }

    // Return true if stock > 0
    bool isAvailable() const {
        return stock > 0;
    }

    // Reduce stock by qty; throw if insufficient
    void reduceStock(int qty) {
        if (qty > stock) {
            throw runtime_error("Insufficient Stock");
        }
        stock -= qty;
    }
};

// ─────────────────────────────────────────────
//  2. CART ITEM
// ─────────────────────────────────────────────
struct CartItem {
    Product* product;
    int      quantity;

    CartItem(Product* p, int qty) : product(p), quantity(qty) {}

    // Return price * quantity
    double subtotal() const {
        return product->price * quantity;
    }
};

// ─────────────────────────────────────────────
//  3. CART
// ─────────────────────────────────────────────
class Cart {
public:
    vector<CartItem> items;
    // Add product to cart (merge if already present)
    void addItem(Product* p, int qty) {
        for(auto &item : items){
            if(item.product->id == p->id){
                item.quantity += qty;
                return;
            }
        }
        items.push_back(CartItem(p, qty));
    }
    // Remove item by product id
    void removeItem(int productId) {
        for(auto it = items.begin(); it != items.end(); it++){
            if(it->product->id == productId){
                items.erase(it);
                return;
            }
        }
    }
    // Sum all CartItem subtotals
    double total() const {
        double sum = 0;

        for(auto item : items){
            sum += item.subtotal();
        }

        return sum;
    }
    // Empty the cart
    void clear() {
        items.clear();
    }
    // Return number of unique products
    int itemCount() const {
        return items.size();
    }
};
// ─────────────────────────────────────────────
//  4. USER
// ─────────────────────────────────────────────
class User {
public:
    int         id;
    string name;
    string email;
    Cart        cart;
    string password;
    string address;
    string phoneNumber;
    bool        isLoggedIn;

    User(int id, const string& name, const string& email)
        : id(id), name(name), email(email) {
        password = "";
        address = "";
        phoneNumber = "";
        isLoggedIn = false;
    }
    void login() {
        isLoggedIn = true;
        cout << "User logged in" << endl;
    }
    void logout() {
        isLoggedIn = false;
        cout << "User logged out" << endl;
    }
    void changePassword(const string& newPassword) {
        password = newPassword;
        cout << "Password updated" << endl;
    }
    void updateAddress(const string& newAddress) {
        address = newAddress;
        cout << "Address updated" << endl;
    }
    void updatePhoneNumber(const string& newPhone) {
        phoneNumber = newPhone;
        cout << "Phone number updated" << endl;
    }
    void displayProfile() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
    }
};
// ─────────────────────────────────────────────
//  5. ORDER
// ─────────────────────────────────────────────
enum class OrderStatus { PENDING, CONFIRMED, SHIPPED, DELIVERED, CANCELLED };
class Order {
public:
    int                   id;
    User* user;
    vector<CartItem> items;
    double                totalAmount;
    OrderStatus           status;
    Order(int id, User* u, const vector<CartItem>& items, double total)
        : id(id), user(u), items(items),
          totalAmount(total), status(OrderStatus::PENDING) {}

    // Move status to the next logical state
    void advanceStatus() {
        if(status == OrderStatus::PENDING)
            status = OrderStatus::CONFIRMED;
        else if(status == OrderStatus::CONFIRMED)
            status = OrderStatus::SHIPPED;
        else if(status == OrderStatus::SHIPPED)
            status = OrderStatus::DELIVERED;
    }
    // Cancel only if status is PENDING or CONFIRMED
    void cancel() {
        if(status == OrderStatus::PENDING ||
           status == OrderStatus::CONFIRMED)
            status = OrderStatus::CANCELLED;
    }
    // Return string name of current status
    string statusString() const {
        if(status == OrderStatus::PENDING)
            return "PENDING";
        else if(status == OrderStatus::CONFIRMED)
            return "CONFIRMED";
        else if(status == OrderStatus::SHIPPED)
            return "SHIPPED";
        else if(status == OrderStatus::DELIVERED)
            return "DELIVERED";
        else
            return "CANCELLED";
    }
};
// ─────────────────────────────────────────────
//  6. PAYMENT
// ─────────────────────────────────────────────
enum class PaymentStatus { PENDING, SUCCESS, FAILED, REFUNDED };
class Payment {
public:
    int           id;
    Order* order;
    double        amount;
    string   method;   // "CARD" | "UPI" | "WALLET"
    PaymentStatus status;
    Payment(int id, Order* order, double amount, const string& method)
        : id(id), order(order), amount(amount),
          method(method), status(PaymentStatus::PENDING) {}

    // Simulate payment processing; set SUCCESS or FAILED
    bool process() {
        status = PaymentStatus::SUCCESS;
        return true;
    }
    // Refund only if status is SUCCESS
    void refund() {
        if(status == PaymentStatus::SUCCESS)
            status = PaymentStatus::REFUNDED;
    }
};
// ─────────────────────────────────────────────
//  7. INVENTORY MANAGER
// ─────────────────────────────────────────────
class InventoryManager {
public:
    map<int, Product*> catalog;  // productId -> Product*
    void addProduct(Product* p) { 
        catalog[p->id] = p; 
    }
    // Return all products with stock > 0
    vector<Product*> getAvailable() const {
        vector<Product*> availableProducts;

        for(auto item : catalog){
            if(item.second->stock > 0)
                availableProducts.push_back(item.second);
        }
        return availableProducts;
    }
    // Return products matching category (case-insensitive)
    vector<Product*> filterByCategory(const string& cat) const {
        vector<Product*> result;
        string category = cat;
        transform(category.begin(), category.end(), category.begin(), ::tolower);

        for(auto item : catalog){
            string pCategory = item.second->category;
            transform(pCategory.begin(), pCategory.end(), pCategory.begin(), ::tolower);

            if(pCategory == category)
                result.push_back(item.second);
        }
        return result;
    }
    // Return products with price between lo and hi
    vector<Product*> filterByPrice(double lo, double hi) const {
        vector<Product*> result;

        for(auto item : catalog){
            if(item.second->price >= lo && item.second->price <= hi)
                result.push_back(item.second);
        }
        return result;
    }
    // Return products whose name contains query (case-insensitive)
    vector<Product*> search(const string& query) const {
        vector<Product*> result;

        string q = query;
        transform(q.begin(), q.end(), q.begin(), ::tolower);

        for(auto item : catalog){
            string name = item.second->name;
            transform(name.begin(), name.end(), name.begin(), ::tolower);

            if(name.find(q) != string::npos)
                result.push_back(item.second);
        }
        return result;
    }
};
// ─────────────────────────────────────────────
//  8. ORDER MANAGER
// ─────────────────────────────────────────────
class OrderManager {
public:
    vector<Order> orders;
    int nextId = 1;

    // Create order from user's cart, reduce stock, clear cart
    Order* placeOrder(User& user) {
        for(auto item : user.cart.items){
            item.product->reduceStock(item.quantity);
        }
        double total = user.cart.total();
        orders.push_back(
            Order(nextId, &user, user.cart.items, total)
        );
        nextId++;
        user.cart.clear();
        return &orders.back();
    }
    // Return all orders for a given user id
    vector<Order*> getOrdersForUser(int userId) {
        vector<Order*> result;
        for(auto &order : orders){
            if(order.user->id == userId)
                result.push_back(&order);
        }
        return result;
    }
};

int main() {
    // Create Inventory
    InventoryManager inventory;
    Product p1(1, "Mechanical Keyboard", 4999, 10, "Electronics");
    Product p2(2, "Headphones", 8999, 5, "Electronics");
    Product p3(3, "T-Shirt", 499, 50, "Clothing");
    inventory.addProduct(&p1);
    inventory.addProduct(&p2);
    inventory.addProduct(&p3);

    // Create User
    User user(1, "Alice", "alice@gmail.com");
    user.login();
    // Add products to cart
    user.cart.addItem(&p1, 2);
    user.cart.addItem(&p3, 3);
    cout << "Cart Total = " << user.cart.total() << endl;
    cout << "Unique Items = " << user.cart.itemCount() << endl;
    // Place Order
    OrderManager orderManager;
    Order* order = orderManager.placeOrder(user);
    cout << "\nOrder ID: " << order->id << endl;
    cout << "Order Status: " << order->statusString() << endl;
    // Advance Order
    order->advanceStatus();
    cout << "After Advance: " << order->statusString() << endl;
    // Payment
    Payment payment(1, order, order->totalAmount, "UPI");
    if (payment.process())
        cout << "Payment Successful" << endl;
    payment.refund();
    // Display remaining stock
    cout << "\nRemaining Stock:" << endl;
    cout << p1.name << " : " << p1.stock << endl;
    cout << p2.name << " : " << p2.stock << endl;
    cout << p3.name << " : " << p3.stock << endl;
    // Available Products
    vector<Product*> available = inventory.getAvailable();
    cout << "\nAvailable Products:" << endl;
    for (auto p : available) {
        cout << p->id << " "
                  << p->name << " "
                  << p->price << " "
                  << p->stock << endl;
    }
    // Orders of User
    vector<Order*> userOrders = orderManager.getOrdersForUser(1);
    cout << "\nOrders of Alice: " << userOrders.size() << endl;
    user.logout();
    return 0;
}