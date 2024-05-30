#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Item {
    std::string name;
    std::string category;
    float price;
    int quantity;
    std::string company;
};
void display_items(const std::vector<Item>& item_array) {
    for (const auto& item : item_array) {
        std::cout << "Name: " << item.name << std::endl;
        std::cout << "Category: " << item.category << std::endl;
        std::cout << "Price: " << item.price << std::endl;
        std::cout << "Quantity: " << item.quantity << std::endl;
        std::cout << "Company: " << item.company << std::endl;
        std::cout << std::endl;
    }
}

void add_item(std::vector<Item>& item_array) {
    Item new_item;
    std::cout << "Enter name: ";
    std::cin.ignore();
    std::getline(std::cin, new_item.name);
    std::cout << "Enter category: ";
    std::getline(std::cin, new_item.category);
    std::cout << "Enter price: ";
    std::cin >> new_item.price;
    std::cout << "Enter quantity: ";
    std::cin >> new_item.quantity;
    std::cout << "Enter company: ";
    std::cin.ignore();
    std::getline(std::cin, new_item.company);
    item_array.push_back(new_item);
}

void update_item(std::vector<Item>& item_array, const std::string& nameToUpdate, const std::string& companyToUpdate) {
    for (auto& item : item_array) {
        if (item.name == nameToUpdate && item.company == companyToUpdate) {
            std::cout << "Enter new name: ";
            std::cin.ignore();
            std::getline(std::cin, item.name);
            std::cout << "Enter new category: ";
            std::getline(std::cin, item.category);
            std::cout << "Enter new price: ";
            std::cin >> item.price;
            std::cout << "Enter new quantity: ";
            std::cin >> item.quantity;
            std::cout << "Enter new company: ";
            std::cin.ignore();
            std::getline(std::cin, item.company);
            std::cout << "Item updated!" << std::endl;
            return;
        }
    }
    std::cout << "Item not found!" << std::endl;
}

void remove_item(std::vector<Item>& item_array, const std::string& nameToRemove, const std::string& companyToRemove) {
    item_array.erase(
            std::remove_if(item_array.begin(), item_array.end(), [&](const Item& item) {
                return item.name == nameToRemove && item.company == companyToRemove;
            }),
            item_array.end()
    );
}

void sort_items(std::vector<Item>& item_array, int choice) {
    switch (choice) {
        case 1:
            std::sort(item_array.begin(), item_array.end(), [](const Item& a, const Item& b) {
                return a.name < b.name;
            });
            break;
        case 2:
            std::sort(item_array.begin(), item_array.end(), [](const Item& a, const Item& b) {
                return a.quantity < b.quantity;
            });
            break;
        case 3:
            std::sort(item_array.begin(), item_array.end(), [](const Item& a, const Item& b) {
                return a.price < b.price;
            });
            break;
        case 4:
            std::sort(item_array.begin(), item_array.end(), [](const Item& a, const Item& b) {
                return a.category < b.category;
            });
            break;
        default:
            std::cout << "Invalid choice. Sorting by name by default." << std::endl;
            std::sort(item_array.begin(), item_array.end(), [](const Item& a, const Item& b) {
                return a.name < b.name;
            });
            break;
    }
}



// Function to clear the console screen
void clear_screen() {
    // Clear the console screen
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix/Linux
#endif
}


int main() {
    std::vector<Item> item_array;

    int choice;
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Display items" << std::endl;
        std::cout << "2. Add item" << std::endl;
        std::cout << "3. Update item" << std::endl;
        std::cout << "4. Remove item" << std::endl;
        std::cout << "5. Sort items" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                display_items(item_array);
                break;
            case 2:
                add_item(item_array);
                break;
            case 3: {
                std::cin.ignore();
                std::string nameToUpdate, companyToUpdate;
                std::cout << "Enter name of item to update: ";
                std::getline(std::cin, nameToUpdate);
                std::cout << "Enter company of item to update: ";
                std::getline(std::cin, companyToUpdate);
                update_item(item_array, nameToUpdate, companyToUpdate);
                break;
            }
            case 4: {
                std::cin.ignore();
                std::string nameToRemove, companyToRemove;
                std::cout << "Enter name of item to remove: ";
                std::getline(std::cin, nameToRemove);
                std::cout << "Enter company of item to remove: ";
                std::getline(std::cin, companyToRemove);
                remove_item(item_array, nameToRemove, companyToRemove);
                break;
            }
            case 5:
                std::cout << "Sort options:" << std::endl;
                std::cout << "1. Sort by name" << std::endl;
                std::cout << "2. Sort by quantity" << std::endl;
                std::cout << "3. Sort by price" << std::endl;
                std::cout << "4. Sort by category" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                sort_items(item_array, choice);
                break;
            case 6:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
