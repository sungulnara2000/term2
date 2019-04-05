//
// Created by gulnara on 31.03.19.
//

#include <iostream>
#include "State.h"

ull get_mask[] = {0xF000000000000000, 0x0F00000000000000, 0x00F0000000000000,
                  0x000F000000000000, 0x0000F00000000000, 0x00000F0000000000,
                  0x000000F000000000, 0x0000000F00000000, 0x00000000F0000000,
                  0x000000000F000000, 0x0000000000F00000, 0x00000000000F0000,
                  0x000000000000F000, 0x0000000000000F00, 0x00000000000000F0, 0x000000000000000F,};

ull set_mask[] = {0x0FFFFFFFFFFFFFFF, 0xF0FFFFFFFFFFFFFF, 0xFF0FFFFFFFFFFFFF,
                  0xFFF0FFFFFFFFFFFF, 0xFFFF0FFFFFFFFFFF, 0xFFFFF0FFFFFFFFFF,
                  0xFFFFFF0FFFFFFFFF, 0xFFFFFFF0FFFFFFFF, 0xFFFFFFFF0FFFFFFF,
                  0xFFFFFFFFF0FFFFFF, 0xFFFFFFFFFF0FFFFF, 0xFFFFFFFFFFF0FFFF,
                  0xFFFFFFFFFFFF0FFF, 0xFFFFFFFFFFFFF0FF, 0xFFFFFFFFFFFFFF0F, 0xFFFFFFFFFFFFFFF0,};

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

State State::up() const {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.path = this->path;

    ull value = get_value(spacePos - 4);
    moved.set_value(spacePos - 4, 0);
    moved.set_value(spacePos, value);
    moved.spacePos -= 4;
    moved.path.push_back('U');

    return moved;
}

State State::down() const {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.path = this->path;

    ull value = get_value(spacePos + 4);
    moved.set_value(spacePos + 4, 0);
    moved.set_value(spacePos, value);
    moved.spacePos += 4;
    moved.path.push_back('D');

    return moved;
}

State State::left() const {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.path = this->path;

    ull value = get_value(spacePos - 1);
    moved.set_value(spacePos - 1, 0);
    moved.set_value(spacePos, value);
    --moved.spacePos;
    moved.path.push_back('L');

    return moved;
}

State State::right() const {
    State moved;
    moved.spacePos = this->spacePos;
    moved.row = this->row;
    moved.path = this->path;

    ull value = get_value(spacePos + 1);
    moved.set_value(spacePos + 1, 0);
    moved.set_value(spacePos, value);
    ++moved.spacePos;
    moved.path.push_back('R');

    return moved;
}