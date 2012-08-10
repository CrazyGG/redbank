#ifndef RED_BANK_LIBRARY_MANAGER_H
#define RED_BANK_LIBRARY_MANAGER_H

#include <redbank/platform.h>
#include <redbank/library.h>

#include <vector>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

/**
*
*/
class LibraryManager {
public:
    LibraryManager(const vector& seerch_paths);

    ~LibraryManager();
public:

    const Library& getLibrary(const String& libName,const String& version = "");

private:
    class Impl;
    shared_ptr<Impl> impl;

};

#endif // RED_BANK_LIBRARY_MANAGER_H
