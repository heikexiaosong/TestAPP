//
// Created by zeus on 1/11/19.
//

#include "math.h"

namespace testapp {


    Math::Math(){
    }

    Math::~Math() {
    }

/**
 * Returns the version identifier as a static string. Do not delete.
 */
    const char* Math::Version() {
        return PACKAGE_VERSION;
    }

}
