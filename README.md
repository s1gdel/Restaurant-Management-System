

Overview:
This project is a simple restaurant menu ordering system implemented in C++. It allows users to interact with a menu, select items, place orders, and associate them with specific tables. The system is designed for a restaurant setting, providing functionalities to handle multiple tables, different menu items, and custom orders.

Features:
- Menu Handling: A predefined menu with item codes, names, and prices.
- Table Management: Supports multiple tables, each with its own seat capacity.
- Order Placement: Users can place orders by selecting items from the menu.
- Order Management: Keeps track of orders for different tables.

File Structure:

Source Files:
- main.cpp: Handles user interactions, table and menu management, and order processing.
- Menu.cpp: Defines the menu and methods for displaying and managing menu operations.
- MenuItem.cpp: Represents individual items on the menu, including item code, name, and price.
- Order.cpp: Manages order creation for each table.
- Table.cpp: Manages individual tables, including seats and associated orders.

Header Files:
- Menu.hpp: Declarations for menu-related functions.
- MenuItem.hpp: Class definitions for menu items.
- Order.hpp: Declarations for order handling.
- Table.hpp: Defines the structure and behavior of tables.

Configuration Files:
- config.txt: Contains the restaurant menu and table information, such as item codes, names, prices, and seat capacity.

ReadMe:
- README.md: Project documentation that explains the structure and provides usage instructions.

Menu Items (from config.txt):

Appetizers:
- A1 Bruschetta: $5.29
- A2 Caprese Flatbread: $6.10
- A3 Artichoke Spinach Dip: $3.99

Entrees:
- E1 Lasagna Classico: $6.99
- E2 Capellini Pomodoro: $7.99

Desserts & Drinks:
- D1 Tiramisu: $2.99
- S1 Soda: $1.99

Table Information:
The restaurant supports multiple tables with varying seating capacities, from small (2 seats) to large tables (up to 20 seats).

How to Run:
1. Clone the repository.
2. Compile the C++ files using a C++ compiler (e.g., g++).
3. Run the compiled binary:
   ```bash
   ./restaurant_ordering_system
   ```
4. Follow the on-screen instructions to view the menu, select items, and place orders for different tables.

Future Improvements:
- Adding user authentication for restaurant staff.
- Enhancing the menu to allow dynamic updates.
- Including a bill calculation and checkout feature.
