#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Restaurant {
private:
    static int coupons_redeemed_count;
    string restaurant_name;
    string location;
    string menu_list[3];
    double price_list[3];
    string valid_coupon_codes_list[1];
public:
    Restaurant(string name, string loc, string menu[], double prices[], string coupons[]) {
        restaurant_name = name;
        location = loc;
        for(int i = 0; i < 3; ++i) {
            menu_list[i] = menu[i];
            price_list[i] = prices[i];
        }
        valid_coupon_codes_list[0] = coupons[0];
    }

    void display_menu() {
        cout << "Menu for " << restaurant_name << ":" << endl;
        for(int i = 0; i < 3; ++i) {
            cout << menu_list[i] << ": $" << price_list[i] << endl;
        }
    }

    double generate_bill(string items[]) {
        double total = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(menu_list[i] == items[j]) {
                    total += price_list[i];
                }
            }
        }
        return total;
    }

    void apply_discount(string coupon_code) {
        if(coupon_code == valid_coupon_codes_list[0]) {
            ++coupons_redeemed_count;
            cout << "Discount Applied: BOGO Offer" << endl;
        } else {
            cout << "Invalid Coupon Code" << endl;
        }
    }

    static int get_coupons_redeemed_count() {
        return coupons_redeemed_count;
    }
};

int Restaurant::coupons_redeemed_count = 0;

class BOGOCoupon {
private:
    string coupon_code;
    time_t valid_from;
    time_t valid_until;
    string restaurant_code;
public:
    BOGOCoupon(string code, time_t from, time_t until, string rest_code) {
        coupon_code = code;
        valid_from = from;
        valid_until = until;
        restaurant_code = rest_code;
    }

    string get_coupon_code() const {
        return coupon_code;
    }

    bool is_valid(string rest_code) const {
        time_t now = time(0);
        return (restaurant_code == rest_code) && (difftime(now, valid_from) >= 0) && (difftime(valid_until, now) >= 0);
    }
};

class User {
private:
    string name;
    int age;
    string mobile_number;
    BOGOCoupon* coupons_list[10];
    int coupons_count;
    BOGOCoupon* redeemed_coupons_list[10];
    int redeemed_coupons_count;
public:
    User(string n, int a, string mob) {
        name = n;
        age = a;
        mobile_number = mob;
        coupons_count = 0;
        redeemed_coupons_count = 0;
    }

    void accumulate_coupon(BOGOCoupon* coupon) {
        if(coupons_count < 10) {
            coupons_list[coupons_count++] = coupon;
        } else {
            cout << "Cannot accumulate more coupons" << endl;
        }
    }

    bool has_valid_coupon(string restaurant_code, string item) {
        for(int i = 0; i < coupons_count; ++i) {
            if(coupons_list[i]->is_valid(restaurant_code)) {
                return true;
            }
        }
        return false;
    }

    bool redeem_coupon(string coupon_code, string restaurant_code) {
        for(int i = 0; i < coupons_count; ++i) {
            if(coupons_list[i]->is_valid(restaurant_code) && coupons_list[i]->get_coupon_code() == coupon_code) {
                for(int j = 0; j < redeemed_coupons_count; ++j) {
                    if(redeemed_coupons_list[j]->get_coupon_code() == coupon_code) {
                        cout << "Coupon already redeemed" << endl;
                        return false;
                    }
                }
                redeemed_coupons_list[redeemed_coupons_count++] = coupons_list[i];
                for(int k = i; k < coupons_count - 1; ++k) {
                    coupons_list[k] = coupons_list[k + 1];
                }
                --coupons_count;
                return true;
            }
        }
        cout << "Invalid Coupon" << endl;
        return false;
    }
};


int main() {
    // Define menu items, prices, and coupons for Food Haven restaurant
  cout<<"Emaan Arshad 23I-2560\n";
    string food_haven_menu[] = {"Sushi", "Pad Thai", "Mango Tango"};
    double food_haven_prices[] = {10, 12, 8};
    string food_haven_coupons[] = {"FH-BOGO-12345"};

    // Create Food Haven restaurant object
    Restaurant food_haven("Food Haven", "City Center", food_haven_menu, food_haven_prices, food_haven_coupons);

    // Define menu items, prices, and coupons for Pixel Bites restaurant
    string pixel_bites_menu[] = {"Binary Burger", "Quantum Quinoa", "Data Donuts"};
    double pixel_bites_prices[] = {15, 14, 6};
    string pixel_bites_coupons[] = {"PB-BOGO-67890"};

    // Create Pixel Bites restaurant object
    Restaurant pixel_bites("Pixel Bites", "Cyber Street", pixel_bites_menu, pixel_bites_prices, pixel_bites_coupons);

    // Create BOGO coupons for Food Haven and Pixel Bites
    BOGOCoupon fh_coupon("FH-BOGO-12345", time(0), time(0) + 365 * 24 * 60 * 60, "FH");
    BOGOCoupon pb_coupon("PB-BOGO-67890", time(0), time(0) + 365 * 24 * 60 * 60, "PB");

    // Create a user
    User user("Alice", 25, "1234567890");

    // User accumulates coupons
    user.accumulate_coupon(&fh_coupon);
    user.accumulate_coupon(&pb_coupon);

    // Display menus of Food Haven and Pixel Bites restaurants
    cout << "----- Food Haven Menu -----" << endl;
    food_haven.display_menu();
    cout << endl;
    cout << "----- Pixel Bites Menu -----" << endl;
    pixel_bites.display_menu();
    cout << endl;

    // User attempts to redeem coupons
    cout << "Alice attempts to redeem coupons:" << endl;
    if (user.redeem_coupon("FH-BOGO-12345", "FH")) {
        cout << "Alice successfully redeemed Food Haven coupon." << endl;
    }
    if (user.redeem_coupon("PB-BOGO-67890", "PB")) {
        cout << "Alice successfully redeemed Pixel Bites coupon." << endl;
    }

    return 0;
}

 
