#include "Pair.h"

Pair::Pair(bool isDef, int value) :isDefined(isDef), value(value)
{
}

std::ostream& operator<<(std::ostream& os, const Pair& other)
{
    os << "<" << other.isDefined << ", " << other.value << ">" << std::endl;
    return os;
}
