//
// Created by gulnara on 31.03.19.
//

#include <iostream>
#include <cmath>
#include "State.h"

vector<ull> get_mask = {};

vector<ull> set_mask = {};

void declare_masks() {
    get_mask.push_back(0xF000000000000000);
    for (int i = 0; i < 15; ++i) {
        get_mask.push_back(get_mask.back() / 16);
    }
    set_mask = {0x0FFFFFFFFFFFFFFF, 0xF0FFFFFFFFFFFFFF, 0xFF0FFFFFFFFFFFFF,
                0xFFF0FFFFFFFFFFFF, 0xFFFF0FFFFFFFFFFF, 0xFFFFF0FFFFFFFFFF,
                0xFFFFFF0FFFFFFFFF, 0xFFFFFFF0FFFFFFFF, 0xFFFFFFFF0FFFFFFF,
                0xFFFFFFFFF0FFFFFF, 0xFFFFFFFFFF0FFFFF, 0xFFFFFFFFFFF0FFFF,
                0xFFFFFFFFFFFF0FFF, 0xFFFFFFFFFFFFF0FF, 0xFFFFFFFFFFFFFF0F, 0xFFFFFFFFFFFFFFF0};
}

void State::set_value(int position, ull value) {
    row = ((row & set_mask[position]) | (value << (15 - position) * 4));
}

ull State::get_value(int position) const {
    return ((row & get_mask[position]) >> (15 - position) * 4);
}

State::State(vector<int> &combination) {
    for (int i = 0; i < 16; i++) {
        set_value(i, combination[i]);
        if (combination[i] == 0) {
            spacePos = i;
        }
    }
}

State State::move(char letter) const {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.path = this->path;

    int bias = 0;
    switch(letter)
    {
        case 'U':
            bias = -4;
            break;
        case 'D':
            bias = 4;
            break;
        case 'L':
            bias = -1;
            break;
        case 'R':
            bias = 1;
            break;
    }

    ull value = get_value(spacePos + bias);
    moved.set_value(spacePos + bias, 0);
    moved.set_value(spacePos, value);
    moved.spacePos += bias;
    moved.path.push_back(letter);

    return moved;
}