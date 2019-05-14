/**
 *
 * @file   TestFunctor.cpp
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    27/04/2010
 *
 * @version V1.0
 *
 * @brief   Premier functor
 *
 **/
#include <iostream>
#include <cassert>
#include <cctype>  // tolower(), toupper()
#include <string>

using namespace std;

namespace
{
    class ToLower
    {
        public:
            virtual int operator() (int i) {
                return tolower(i);
            }
            virtual ~ToLower(){}

    }; // ToLower

    typedef int (* fctInt2Int_t) (int);
    string & moulinette (string & str, ToLower transf)
    {
        for (string::size_type i (str.size ()); i--; )
            str [i] = transf (str [i]);

        return str;

    } // moulinette()

    void testFunctor (void)
    {
        cout << "Functor : ";

        string ligne  ("AZECv qrgWSg wrV  wfdgWFDHG  wdfGWXCV");
        string minusc ("azecv qrgwsg wrv  wfdgwfdhg  wdfgwxcv");

        // ToDo
        assert (minusc == moulinette (ligne, ToLower()));

        cout << "OK\n";

    } // testFunctor()

} // namespace anonyme

int main (void)
{
    /*      */    testFunctor ();     /*           */

    return 0;

} // main()
