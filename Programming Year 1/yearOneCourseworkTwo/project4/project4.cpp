#include <iostream>
#include <string>

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

    string getCustomerAddress() {
        return customerAddress;
    }
};

class Order {
private:
    Customer customer;
    MenuItem menuitem;
    int orderCounter = 0;
public:
    Order(string customerName, string customerAddress, string customerPhoneNumber, string itemName, bool availability, double itemPrice, double popularityRating, string cuisine) 
    : customer(customerName, customerAddress, customerPhoneNumber)
    , menuitem(itemName, availability, itemPrice, popularityRating, cuisine) {
        this->orderCounter = orderCounter;
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

};

int main() {

}