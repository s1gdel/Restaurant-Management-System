#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Menu.hpp"
#include "Table.hpp"
#include "Order.hpp"

using namespace std;

int main()
{
    ifstream finput("config.txt");
    Menu menu(finput);

    int numTables;
    finput >> numTables;

    string line;
    getline(finput, line);

    Table **tables = new Table*[numTables];
    int tableId, capacity;
    for(int i = 0; i < numTables; i++) {
        finput >> tableId >> capacity;
        tables[tableId - 1] = new Table(tableId, capacity);
    }

    finput.close();

    string command;
    while (true) {
        getline(cin, command);
        if (cin.fail() || command == "C")
        {
          break;
        }

        istringstream iss(command);
        int tableNumber;
        char operation;
        iss >> tableNumber >> operation;

        switch(operation) {
            case 'P': {
                int partySize;
                iss >> partySize;
                if (tableNumber > 0 && tableNumber <= numTables)
                    tables[tableNumber - 1]->seatParty(partySize);
                break;
            }
            case 'O': {
                string orderDetails;
                getline(iss, orderDetails);
                if (tableNumber > 0 && tableNumber <= numTables)
                    tables[tableNumber - 1]->placeOrder(orderDetails, &menu);
                break;
            }
            case 'S': {
                if (tableNumber > 0 && tableNumber <= numTables)
                    tables[tableNumber - 1]->serve();
                break;
            }
            case 'C': {
                if (tableNumber > 0 && tableNumber <= numTables)
                    tables[tableNumber - 1]->cleanup();
                break;
            }
            default:
                cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
