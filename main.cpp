
#include <iostream>


#include <string>

#include "gui_helper.h"
#include "calculations.h"

int main() {

    auto a = ptv::calculate_warranty(399);
    std::cout << static_cast<int>(a) << '\n';
    a = ptv::calculate_warranty(501);

    std::cout << static_cast<int>(a) << '\n';
    a = ptv::calculate_warranty(1001);

    std::cout << static_cast<int>(a) << '\n';


    nana::form fm{};
    nana::label lb{fm};

    nana::label price_lbl{fm};
    nana::textbox price_tb{fm};
    nana::label percent_lbl{fm};
    nana::textbox percent_tb{fm};
    nana::textbox item_num_tb{fm};
    nana::textbox formula_tb{fm};

    price_lbl.caption("TV Price");
    percent_lbl.caption("Amount to take off");
    price_tb.set_accept(ptv::numbers_only);
    percent_tb.set_accept(ptv::numbers_only);
    item_num_tb.editable(false);
    ptv::set_textbox_text(percent_tb, "0.30");
    ptv::set_textbox_text(price_tb, "0");
    formula_tb.editable(false);

    auto lcalc = [& price_tb, &percent_tb, &item_num_tb, &formula_tb]() {
        auto price_val = price_tb.text().empty() ? 0 : std::stold(price_tb.text());
        auto percent_val = percent_tb.text().empty() ? 0 : std::stold(percent_tb.text());
        auto calculated_val = ptv::calculate(price_val, percent_val);
        auto warranty_val{ptv::calculate_warranty(calculated_val)};
        std::string formula { std::to_string(calculated_val) + " " + std::to_string(ptv::get_warranty_price(warranty_val)) };

        ptv::set_textbox_text(item_num_tb, ptv::calculate_warranty_str(warranty_val).c_str());
        ptv::set_textbox_text(formula_tb, formula.c_str());
    };

    price_tb.events().key_press (lcalc);
    percent_tb.events().key_press (lcalc);





    lb.caption("test");
    nana::textbox tb{fm};
    lb.format(true);
    tb.set_accept(ptv::numbers_only);

    nana::place layout{fm};
    layout.div("vert margin=5% size=15% <<price_lbl> <price_tb>> <<percent_lbl><percent_tb>><item_num> <formula>");
    layout["price_lbl"] << price_lbl;
    layout["price_tb"] << price_tb;
    layout["percent_lbl"] << percent_lbl;
    layout["percent_tb"] << percent_tb;
    layout["item_num"] << item_num_tb;
    layout["formula"] << formula_tb;

    layout.collocate();
    fm.show();
    fm.events().resized([](nana::arg_resized const & a){  std::cout << a.height << ',' << a.width << '\n';});
    nana::exec();
}

