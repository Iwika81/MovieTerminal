#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    
    
    
    
    
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    printf("columns: %d\n", columns);
    printf("rows: %d\n", rows);

    std::string line;

    std::getline(std::cin, line);  // read a line from std::cin into line

    std::cout << "Your Line Was (" << line << ")\n";

    std::getline(std::cin, line); 
    
    int x , y;

    x=GetSystemMetrics( SM_CXSCREEN );
    y=GetSystemMetrics( SM_CYSCREEN );

    cout<<"ancho = "<<x<<" x "<<"alto = "<<y;

    getchar();
    system("PAUSE");
    system("cls");
    return EXIT_SUCCESS;
}

