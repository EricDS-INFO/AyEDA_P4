#include<cstdlib>

#define BOUND 100000000

dni::dni()
{
    value_ = rand() % BOUND;
    length_ = std::to_string(value_).length();
}


dni::dni(int seed)
{   srand(seed);
    value_ = rand() % BOUND;
    length_ = std::to_string(value_).length();
}

dni::~dni(){}

std::ostream& operator<< (std::ostream& os, dni dni_t)
{
    switch( dni_t.length() )
    {
        case 1:
            os << "- 0000000" <<  dni_t.value() << " -\n";
            break;

        case 2:
            os << "- 000000" <<  dni_t.value() << " -\n";
            break;

        case 3:
            os << "- 00000" <<  dni_t.value() << " -\n";
            break;

        case 4:
            os << "- 0000" <<  dni_t.value() << " -\n";
            break;

        case 5:
            os << "- 000" <<  dni_t.value() << " -\n";
            break;

        case 6:
            os << "- 00" <<  dni_t.value() << " -\n";
            break;

        case 7:
            os << "- 0" <<  dni_t.value() << " -\n";
            break;

        case 8:
            os << "- " <<  dni_t.value() << " -\n";
            break;

        default:
            os << "- XXXXXXXX -\n";
            break;
    }
}