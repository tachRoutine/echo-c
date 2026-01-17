#include <string.h>
#include <unistd.h>
#include <stdbool.h>

struct Options {
    bool print_newline;
};

int main(int argc, char **argv){
    struct Options default_options = {true};

    for (int i = 1; i < argc; i++) {
        write(1, argv[i], strlen(argv[i]));
        
        if (i < argc - 1){
            write(1," ",1);
        }
    }
    
    if(default_options.print_newline){
        write(1,"\n",1);
    }
    return 0;
}