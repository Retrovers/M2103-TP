#include <iostream>
#include <CException.h>
#include <CstCodErr.h>

using namespace std;

void testExceptionsInMain(){
    //throw exception();
    //throw runtime_error("bjr");
    //throw nsUtil::CException("lol");
    //throw int();
}

int main(){

    try {
        testExceptionsInMain();
    } catch (exception e){
        cout << "Error ! Exception say : "  << e.what() << endl;
    } catch (nsUtil::CException e){
        cout << "Error ! Exception say : " <<  e.what() << endl;
    } catch (runtime_error e){
        cout << "Error ! Exception say : " <<  e.what() << endl;
    } catch (int i){
        cout << "Error ! Exception say : " <<  i << endl;
    } catch (...){
        cout << "Tiene una errora" << endl;
    }


}
