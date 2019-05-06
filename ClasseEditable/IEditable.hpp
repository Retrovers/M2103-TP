#include <ostream>

using namespace std;

namespace nsUtil {

    class IEditable {
        public:

            virtual void display(ostream & os) const = 0;

            friend ostream & operator << (ostream & os, const IEditable & editable)
            {
                editable.display (os);
                return os;

            } // operator <<()

            ~IEditable(){}

    };
}





