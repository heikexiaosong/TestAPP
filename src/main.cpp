#include <iostream>

#include "api/test.h"

using namespace std;

int main(int argc, char** argv) {

    test::TestApi api;

    std::cout << api.Version() << std::endl;

    return 0;
}
