//
// Created by zeus on 1/11/19.
//

#include "test.h"

namespace test {


    TestApi::TestApi(){
    }

    TestApi::~TestApi() {
    }

/**
 * Returns the version identifier as a static string. Do not delete.
 */
    const char* TestApi::Version() {
        return PACKAGE_VERSION;
    }

}
