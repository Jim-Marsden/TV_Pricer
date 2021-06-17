//
// Created by snizzfox on 6/16/21.
//

#ifndef TV_PRICER_GUI_HELPER_H
#define TV_PRICER_GUI_HELPER_H

#include <string>
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/textbox.hpp>

namespace ptv{

    constexpr auto layout_raw{L"<><><>"};
    bool numbers_only(wchar_t letter);
    void set_textbox_text(nana::textbox & textBox, char const * str);


}//namespace ptv{



#endif //TV_PRICER_GUI_HELPER_H
