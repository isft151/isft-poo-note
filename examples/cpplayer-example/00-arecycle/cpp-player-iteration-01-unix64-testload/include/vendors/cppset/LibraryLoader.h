/**
* Copyright (c) 2016 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* This file is part of CPPSET.
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/

#ifndef LIBRARY_LOADER_H
#define LIBRARY_LOADER_H

#ifdef __unix__
    #define RTLD_LAZY   1
    #define RTLD_NOW    2
    #define RTLD_GLOBAL 4
    #include <vendors/dlopen/dlfcn.h>
#elif __APPLE__
    #include <vendors/dlopen/dlfcnMac.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <string>
#include <iostream>

#include <memory>
#include <typeinfo>

class LibraryLoader
{
    private:
        void* library;
        void* symbol;
        bool freedom;
        bool isLoaded;

        void showError(string message, string message2 = "")
        {
            cerr << message << ' ' << message2 << endl;
            exit(EXIT_FAILURE);
        }

    public:
        LibraryLoader(){}
        virtual ~LibraryLoader(){freeLibrary();}
        

        void* loadLibrary(std::string filePath)
        {
            #ifdef __unix__
                filePath += ".so";
                library = dlopen(filePath.c_str(), RTLD_NOW);
            #elif __APPLE__
                filePath += ".dylib";
                library = dlopen(filePath.c_str(), RTLD_LOCAL|RTLD_LAZY);
            #elif defined(_WIN32) || defined(WIN32)
                filePath += ".dll";
                library = (void*) LoadLibrary(filePath.c_str());
            #endif // defined

            (library) ? isLoaded = true : isLoaded = false;
            if(!isLoaded) showError("File Not Found, Error Loading!");

            return library;
        }

        void* getExternSymbol(std::string name)
        {
            if(isLoaded)
            {
                #ifdef __unix__
                    symbol = dlsym(library, name.c_str());
                #elif __APPLE__
                    symbol = dlsym(library, name.c_str());
                #elif defined(_WIN32) || defined(WIN32)
                    symbol = (void*) GetProcAddress((HINSTANCE)library, name.c_str());
                #endif // defined                
            }
            else
            {
                showError("Library not loaded!");
            }
            

            return symbol;
        }

        template<typename ObjectType> ObjectType getObject(std::string symbolName)
        {
            ObjectType obj = null;
            if(isLoaded)
            {
                if( dynamic_cast<ObjectType> ( getExternSymbol(symbolName) ) != nullptr )
                {
                    obj = ( ObjectType ) getExternSymbol(symbolName);
                }
                else
                {
                    showError("Incorrect ObjectType!");
                }
            }
            return obj;        
        }

        bool LibraryLoader::freeLibrary()
        {
            if(isLoaded)
            {
                #ifdef __unix__
                    freedom = dlclose(library);
                #elif __APPLE__
                    freedom = dlclose(library);
                #elif defined(_WIN32) || defined(WIN32)
                    freedom = FreeLibrary((HINSTANCE)library);
                #endif // defined
            }
            else
            {
                showError("Library not loaded!");
            }

            return freedom;
        }
};

#endif // LIBRARY_LOADER_H

