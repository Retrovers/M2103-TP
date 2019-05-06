#ifndef __IEDITABLE_H__
#define __IEDITABLE_H__

#include <ostream>

using namespace std;

namespace nsUtil {

    class IEditable {
        public:
            virtual void display(ostream & os) const = 0;

            inline friend ostream & operator << (ostream & os, const IEditable & editable)
            {
                editable.display (os);
                return os;

            } // operator <<()

            ~IEditable();
    };
}
#endif




