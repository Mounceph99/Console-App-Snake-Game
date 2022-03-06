//
// Created by Mounceph Morssaoui on 2022-03-05.
//

#include "Apple.h"

Apple::Apple() {
}

Apple::Apple(const Apple& apple) {
}

Apple::~Apple() {
}

Apple& Apple::operator=(const Apple &apple) {

    if (this == &apple) {
        return *this;
    }

    return *this;
}

ostream& operator<<(ostream& output, const Apple& apple) {
    return output;
}