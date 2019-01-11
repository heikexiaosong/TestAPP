//
// Created by zeus on 1/11/19.
//

#ifndef TESTAPP_MATH_H
#define TESTAPP_MATH_H

#define PACKAGE_VERSION "1.0.0"

namespace testapp {

    class Math {

    public:
        Math();

        virtual ~Math();

        /**
         * Returns the version identifier as a static string. Do not delete.
         */
        static const char* Version();

    };

}




#endif //TESTAPP_MATH_H
