#include <iostream>

#include "math/math.h"

using namespace std;

int main(int argc, char** argv) {

    testapp::Math math;

    std::cout << math.Version() << std::endl;

    return 0;
}
