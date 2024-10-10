#include "Order.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

Order::Order(string OrderString, Menu *menup)
: numItems(0) {
    addItems(OrderString, menup);
}

void Order::addItems(string OrderString, Menu *menup)
{
    istringstream iss(OrderString);
    string code;
    while (iss >> code)
    {
        MenuItem* item = menup->find(code);
        if (item && numItems < MAX_ITEMS_IN_ORDER)
        {
            items[numItems++] = item;
        } else
        {
            cout << "No item with code " << code << endl;
        }
    }
}

void Order::printReceipt() {
    double total = 0.0;
    for (int i = 0; i < numItems; i++) {
        cout << items[i]->getCode() << items[i]->getName()
        << right << setw(5)<< items[i]->getPrice() << endl;
        total += items[i]->getPrice();
    }
    cout << "Total" << right << setw(5) << total << endl;
}

int Order::getCount() const{
  return numItems;
}
