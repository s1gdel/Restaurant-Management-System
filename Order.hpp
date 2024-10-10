#ifndef ORDER_HPP
#define ORDER_HPP

#include "Menu.hpp"


class Order
{
    public:
        // "A1 A2 B1"
        Order(string OrderString, Menu *menup);
        void addItems(string OrderString, Menu *menup);
        void printReceipt();
        int getCount() const;

    protected:

    private:
        static const int MAX_ITEMS_IN_ORDER = 100;
        int numItems;
        MenuItem *items[MAX_ITEMS_IN_ORDER];
};

#endif // ORDER_H
