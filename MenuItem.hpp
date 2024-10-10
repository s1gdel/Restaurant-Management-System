
#ifndef MENUITEM_HPP
#define MENUITEM_HPP
#include <iostream>

using namespace std;

class MenuItem
{
    public:
        MenuItem(string ccode="", string nname="", double pprice=0);
        string getCode();
        string getName();
        double getPrice();

    protected:

    private:
        string code, name;
        double price;
};

#endif // MENUITEM_H

