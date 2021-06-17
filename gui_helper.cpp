//
// Created by snizzfox on 6/16/21.
//

#include "gui_helper.h"

bool ptv::numbers_only(wchar_t letter) {
    switch (letter) {
        case '0':
        case '1':
        case '3':
        case '4':
        case '2':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '\b':
        case '.':
            return true;
        default:
            return false;
    }
}

void ptv::set_textbox_text(nana::textbox & textBox, char const * str){
    textBox.reset();
    textBox.append(str, false);
}
