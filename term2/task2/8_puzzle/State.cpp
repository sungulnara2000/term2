//
// Created by gulnara on 29.03.19.
//
#include <iostream>

#include "State.h"

ul get_mask[] = {0xF00000000, 0x0F0000000, 0x00F000000, 0x000F00000, 0x0000F0000,
             0x00000F000, 0x000000F00, 0x0000000F0, 0x00000000F};

ul set_mask[] = {0x0FFFFFFFF, 0xF0FFFFFFF, 0xFF0FFFFFF, 0xFFF0FFFFF, 0xFFFF0FFFF,
                 0xFFFFF0FFF, 0xFFFFFF0FF, 0xFFFFFFF0F, 0xFFFFFFFF0};

void State::set_value(int position, ul value) {
//    std::cout << (row & set_mask[position]) << '\n';
//    std::cout << ((row & set_mask[position]) | (value << (8 - position) * 4)) << '\n';
    row = ((row & set_mask[position]) | (value << (8 - position) * 4));
}

ul State::get_value(int position) {
//    std::cout << (row & get_mask[position]) << '\n';
//    std::cout << ((row & get_mask[position]) >> (8 - position) * 4) << '\n';
    return ((row & get_mask[position]) >> (8 - position) * 4);
}

State::State(vector<int> &combination) {
    for (int i = 0; i < 9; i++) {
        set_value(i, combination[i]);
        if (combination[i] == 0) {
            spacePos = i;
        }
    }
}


State State::up() {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.prev = this->row;

    ul value = get_value(spacePos - 3);
    moved.set_value(spacePos - 3, 0);
    moved.set_value(spacePos, value);
    moved.spacePos -= 3;
    moved.move = 'U';

    return moved;
}

State State::down() {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.prev = this->row;

    ul value = get_value(spacePos + 3);
    moved.set_value(spacePos + 3, 0);
    moved.set_value(spacePos, value);
    moved.spacePos += 3;
    moved.move = 'D';

    return moved;
}

State State::left() {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.prev = this->row;

    ul value = get_value(spacePos - 1);
    moved.set_value(spacePos - 1, 0);
    moved.set_value(spacePos, value);
    --moved.spacePos;
    moved.move = 'L';

    return moved;
}

State State::right() {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.prev = this->row;

    ul value = get_value(spacePos + 1);
    moved.set_value(spacePos + 1, 0);
    moved.set_value(spacePos, value);
    ++moved.spacePos;
    moved.move = 'R';

    return moved;
}