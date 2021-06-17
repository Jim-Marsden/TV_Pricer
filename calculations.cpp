//
// Created by snizzfox on 6/15/21.
//

#include "calculations.h"
#include <iostream>

ptv::value_size_t ptv::calculate(ptv::value_size_t price, ptv::value_size_t percent) {

    return  price - (price * percent);

}

ptv::warranty_value ptv::calculate_warranty(ptv::value_size_t calculate_value) {
    if(calculate_value < 500) return ptv::warranty_value::under_500;
    else if(calculate_value < 1000) return ptv::warranty_value::between_500_and_1k;
    else return ptv::warranty_value::over_1k;
}

std::string ptv::calculate_warranty_str(ptv::warranty_value warrantyValue) {
    const auto under_500{"$34.99 Item# 1575678"};
    const auto between_500_1k{"$64.99 Item# 1575685"};
    const auto over_1k{"$99.99 Item# 1575686"};

    switch (warrantyValue) {
        case ptv::warranty_value::under_500 :
            return under_500;
        case ptv::warranty_value::between_500_and_1k:
            return between_500_1k;
        case ptv::warranty_value::over_1k:
            return over_1k;
        default:
            return over_1k;
    }

}

ptv::value_size_t ptv::get_warranty_price(ptv::warranty_value warrantyValue) {
    const auto under_500{34.99}; //{"$34.99 Item# 1575678"};
    const auto between_500_1k{64.99};//{"$64.99 Item# 1575685"};
    const auto over_1k{99.99};//{"$99.99 Item# 1575686"};
    const auto error_val{0.01};

    switch (warrantyValue) {
        case ptv::warranty_value::under_500 :
            return under_500;
        case ptv::warranty_value::between_500_and_1k:
            return between_500_1k;
        case ptv::warranty_value::over_1k:
            return over_1k;
        default:
            return error_val;
    }
}
