#include "Table.hpp"
#include <iostream>
using namespace std;

Table::Table(int tableId, int capacity)
: tableId(tableId), capacity(capacity), partySize(0), status(IDLE), orderp(nullptr) {}

bool Table::seatParty(int numGuests) {
    if (numGuests > capacity) {
        cout << "Sorry, max " << capacity << " seats in Table " << tableId << "!" << endl;
        return false;
    }
    if (status != IDLE) {
        cout << "Table " << tableId << " already occupied!" << endl;
        return false;
    }
    partySize = numGuests;
    status = SEATED;
    cout << "Party of " << numGuests << " assigned to Table " << tableId << endl;
    return true;
}

bool Table::placeOrder(string str, Menu *menu) {
    if (status == IDLE) {
        cout << "No party is seated at Table " << tableId << " yet!" << endl;
        return false;
    }

    bool isFirstOrder = (orderp == nullptr);
    int initialItemsCount = 0;

    if (!isFirstOrder) {
        initialItemsCount = orderp->getCount();
    }

    if (isFirstOrder) {
        orderp = new Order(str, menu);
    } else {
        orderp->addItems(str, menu);
    }

    status = ORDERED;

    int currentItemsCount = orderp->getCount();
    int addedItemsCount = currentItemsCount - initialItemsCount;

    if (isFirstOrder) {
        cout << currentItemsCount << " items ordered for Table " << tableId << endl;
    } else if (addedItemsCount > 0) {
        cout << addedItemsCount << " additional items ordered for Table " << tableId << endl;
    } else {
    }
    return true;
}
bool Table::serve() {
    if (status != ORDERED) {
        cout << "Order not placed at Table " << tableId << " yet!" << endl;
        return false;
    }
    status = SERVED;
    cout << "Food served in table " << tableId << endl;
    return true;
}
bool Table::cleanup() {
    if (status != SERVED) {
        cout << "Food not served for Table " << tableId << " yet!" << endl;
        return false;
    }
    cout << "Table " << tableId << " is closed. Here is the bill." << endl;
    cout<<endl;
    cout<<"Receipt Table# "<<tableId<<" "<<"Party "<<partySize<<endl;
    if (orderp) {
        orderp->printReceipt();
        delete orderp;
        partySize = 0;
        orderp = nullptr;
        status = IDLE;
    }
    return true;
}
