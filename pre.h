#ifdef _WIN32 || _WIN64
	#define CLEAR std::system("cls");
	#define PAUSE std::system("pause");
#else 
    #define CLEAR std::system("clear");
	#define PAUSE std::system("sleep 5s");
#endif