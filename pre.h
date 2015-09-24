#include <cstdlib>;

#ifdef _WIN32 || _WIN64

    void clear() {
        std::system("cls");
    }

#else 
    void clear() {
        std::system("clear")
    }

#endif