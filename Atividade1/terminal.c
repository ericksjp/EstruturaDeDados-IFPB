#include <stdio.h>
#include <unistd.h>

int main() {
#ifdef _WIN32
    printf("Este programa está sendo executado no Windows.\n");

#elif __linux__
    printf("Este programa está sendo executado no Linux.\n");
    
#elif __APPLE__
    printf("Este programa está sendo executado no macOS.\n");
#else
    printf("Este programa está sendo executado em um sistema não reconhecido.\n");
#endif

    return 0;
}