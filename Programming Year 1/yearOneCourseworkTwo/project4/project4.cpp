#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

    /*
    base staff class and the employee classes that inherit from the base
                                                                        */

class Staff {
private:
    string name;
    string address;
    string phoneNumber;
public:
    Staff(string name, string address, string phoneNumber) {
        this->name = name;
        this->address = address;
        this->phoneNumber = phoneNumber;
    }
    string GetName() { 
        return name; 
    }
    string GetAddress() { 
        return address; 
    }
    string GetPhoneNumber() {
        return phoneNumber; 
    }
};

class Chef : public Staff {
private:
    string cuisine;
public:
    Chef(string name, string address, string phoneNumber, string cuisine) : Staff(name, address, phoneNumber) {
        this->cuisine = cuisine;
    }
    string GetCuisine() { 
        return cuisine; 
    }
};

class Manager : public Staff {
public:
    Manager(string name, string address, string phoneNumber) : Staff(name, address, phoneNumber) {

    }
};

class Receptionist : public Staff {
public:
    Receptionist(string name, string address, string phoneNumber) : Staff(name, address, phoneNumber) {

    }
};

class DeliveryStaff : public Staff {
public:
    DeliveryStaff(string name, string address, string phoneNumber) : Staff(name, address, phoneNumber) {

    }
};

class MenuItem {
private:
    string itemName;
    bool availability;
    double itemPrice;
    double popularityRating;
    string cuisine;

public:
    MenuItem(string itemName, bool availability, double itemPrice, double popularityRating, string cuisine) {
        this->itemName = itemName;
        this->availability = availability;
        this->itemPrice = itemPrice;
        this->popularityRating = popularityRating;
        this->cuisine = cuisine;
    }

    string getItemName() {
        return this->itemName;
    }

    void setItemName(string itemName) {
        this->itemName = itemName;
    }

    bool getAvailability() {
        return this->availability;
    }
};

class Customer {
private:
    string customerName;
    string customerAddress;
    string customerPhoneNumber;
public:
    Customer(string customerName, string customerAddress, string customerPhoneNumber) {
        this->customerName = customerName;
        this->customerAddress = customerAddress;
        this->customerPhoneNumber = customerPhoneNumber;
    }

    string getCustomerName() {
        return customerName;
    }

    string getCustomerAddress() {
        return customerAddress;
    }
};

class Order {
private:
    Customer customer;
    MenuItem menuitem;
    int orderCounter = 0;
    static double totalIncome;
public:
    Order(string customerName, string customerAddress, string customerPhoneNumber, string itemName, bool availability, double itemPrice, double popularityRating, string cuisine)
        : customer(customerName, customerAddress, customerPhoneNumber)
        , menuitem(itemName, availability, itemPrice, popularityRating, cuisine) {
        this->orderCounter = orderCounter;
        totalIncome += itemPrice;
    }
    
    bool distanceChecker() {
        if (customer.getCustomerAddress().find("CF37") || customer.getCustomerAddress().find("CF38")) {
            return true;
        }
        else {
            cout << "Distance too far for takeaway, please collect or cancel.\n";
            return false;
        }
    }

    void ordersPerDayCounter() {
        orderCounter++;
    }

    int returnOrderCount() {
        return orderCounter;
    }

 
    static double getTotalIncome() {
        return totalIncome;
    }

    static void resetTotalIncome() {
        totalIncome = 0.0;
    }
};

class Restaurant {
private:
    vector<MenuItem> menuItems;
    vector<Staff> staff;
    vector<Order> orders;
    map<string, int> cuisineCount;
    map<string, int> menuItemCount;
    map<Customer, int> customerOrderCount;

public:
    Restaurant(vector<MenuItem> menuItems, vector<Staff> staff) {
        this->menuItems = menuItems;
        this->staff = staff;
    }

    void placeOrder(string customerName, string customerAddress, string customerPhoneNumber, string itemName, bool availability, double itemPrice, double popularityRating, string cuisine) {
        MenuItem menuItem(itemName, availability, itemPrice, popularityRating, cuisine);
        Customer customer(customerName, customerAddress, customerPhoneNumber);
        Order order(customerName, customerAddress, customerPhoneNumber, itemName, availability, itemPrice, popularityRating, cuisine);
        orders.push_back(order);

        cuisineCount[cuisine]++;
        menuItemCount[itemName]++;
        customerOrderCount[customer]++;
    }

    void generateDailyReport() {
        cout << "There were " << orders.size() << " orders placed today, generating report: \n";
        cout << "Total Income for the day was " << Order::getTotalIncome() << "\n";

        string mostPopularCuisine = "";
        int maxCuisineCount = 0;
        for (auto& c : cuisineCount) {
            if (c.second > maxCuisineCount) {
                maxCuisineCount = c.second;
                mostPopularCuisine = c.first;
            }
        }
        cout << "Most popular cuisine choice was " << mostPopularCuisine << " with " << maxCuisineCount << " orders.\n";

        string mostPopularMenuItem = "";
        int maxMenuItemCount = 0;
        for (auto& m : menuItemCount) {
            if (m.second > maxMenuItemCount) {
                maxMenuItemCount = m.second;
                mostPopularMenuItem = m.first;
            }
        }
        cout << "Most popular menu item was " << mostPopularMenuItem << " with " << maxMenuItemCount << "orders.\n";

        Customer mostLoyalCustomer = Customer("", "", "");
        int maxCustomerOrderCount = 0;
        for (auto& c : customerOrderCount) {
            if (c.second > maxCustomerOrderCount) {
                maxCustomerOrderCount = c.second;
                mostLoyalCustomer = c.first;
            }
        }
        cout << "Most loyal customer was " << mostLoyalCustomer.getCustomerName() << " with " << maxCustomerOrderCount << " orders.\n";
    }
};


int main() {
    vector<MenuItem> menuItems;
        // Add menu items to the vector
    vector<Staff> staff;
        // Add staff to the vector
    Restaurant restaurant(menuItems, staff);

    restaurant.placeOrder("John Doe", "CF37", "123456", "Pizza", true, 10.0, 5.0, "Italian");
    restaurant.placeOrder("Jane Doe", "CF37", "654321", "Pasta", true, 12.0, 4.5, "Italian");
    restaurant.placeOrder("John Doe", "CF37", "123456", "Rice", false, 5.0, 3.5, "Chinese");
    restaurant.generateDailyReport();
}