#ifndef RED_BANK_LIBRARY_H
#define RED_BANK_LIBRARY_H

#include <redbank/platform.h>
#include <boost/shared_ptr.hpp>

class Library
{
public:
     Library(const String& libPath);

     ~Library();
public:
     void* resolve(const char *symbol);

     void* resolve(const String& symbol);

     bool load();

     bool unload();

     bool reload();

     bool isLoaded();

     String get_error_string();
private:
     class Impl;
     shared_ptr<Impl> impl;
};


#endif // RED_BANK_LIBRARY_H
