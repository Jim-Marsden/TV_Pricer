//
// Created by snizzfox on 6/15/21.
//

#ifndef TV_PRICER_CALCULATIONS_H
#define TV_PRICER_CALCULATIONS_H

#include <string>
namespace ptv{
    using value_size_t = long double;
    enum struct warranty_value{
        under_500 = 1,
        between_500_and_1k,
        over_1k,
    };

    value_size_t calculate(value_size_t price, value_size_t percent);

    warranty_value calculate_warranty(value_size_t calculate_value);
    std::string calculate_warranty_str(warranty_value);
    value_size_t get_warranty_price(warranty_value);

} // namespace ptv;

#endif //TV_PRICER_CALCULATIONS_H
