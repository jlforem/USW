#include <iostream>
#include <vector>
#include <string>
using namespace std;

//simulate an input of orders randomly to then generate the report

class Person {
public:
    Person(string name, string address, string phoneNumber)
        : name(name), address(address), phoneNumber(phoneNumber) {
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

private:
    string name;
    string address;
    string phoneNumber;
};

class Staff : public Person {
public:
    Staff(string name, string address, string phoneNumber, string role)
        : Person(name, address, phoneNumber), role(role) {}

    string getRole() {
        return role;
    }

private:
    string role;
};

class Chef : public Staff {
public:
    Chef(string name, string address, string phoneNumber, string cuisine)
        : Staff(name, address, phoneNumber, "Chef"), cuisine(cuisine) {}

    string getCuisine() {
        return cuisine;
    }

private:
    string cuisine;
};

class DeliveryStaff : public Staff {
public:
    DeliveryStaff(string name, string address, string phoneNumber)
        : Staff(name, address, phoneNumber, "Delivery Staff") {}
};

class Manager : public Person {
public:
    Manager(string name, string address, string phoneNumber)
        : Person(name, address, phoneNumber), role("Manager") {
    }

    string getRole() {
        return role;
    }

private:
    string role;
};

class Receptionist : public Person {
public:
    Receptionist(string name, string address, string phoneNumber)
        : Person(name, address, phoneNumber), role("Receptionist") {
    }

    string getRole() {
        return role;
    }

private:
    string role;
};

class MenuItem {
public:
    MenuItem(string cuisine, string itemName, bool availability, double itemPrice, int popularityRating)
        : cuisine(cuisine), itemName(itemName), availability(availability), itemPrice(itemPrice), popularityRating(popularityRating) {}

    string getCuisine() {
        return cuisine;
    }

    string getItemName() {
        return itemName;
    }

    bool getAvailability() {
        return availability;
    }

    double getItemPrice() {
        return itemPrice;
    }

    int getPopularityRating() {
        return popularityRating;
    }

private:
    string cuisine;
    string itemName;
    bool availability;
    double itemPrice;
    int popularityRating;
};

class Order {
public:
    Order(Person customer, MenuItem menuItem, bool typeOfOrder, double totalPrice)
        : customer(customer), menuItem(menuItem), typeOfOrder(typeOfOrder), totalPrice(totalPrice) {}

    Person getCustomer() {
        return customer;
    }

    MenuItem getMenuItem() {
        return menuItem;
    }

    bool getTypeOfOrder() {
        return typeOfOrder;
    }

    double getTotalPrice() {
        return totalPrice;
    }



private:
    Person customer;
    MenuItem menuItem;
    bool typeOfOrder;
    double totalPrice;


};



int main() {
    vector<Order> orders;
    int numOrders;

    cout << "Enter the number of orders: ";
    cin >> numOrders;
}