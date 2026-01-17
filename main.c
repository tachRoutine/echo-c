#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

struct Options {
    bool print_newline;
    bool interpret_escapes;
};

int main(int argc, char **argv){
    int arg_start_index = 1;
    struct Options default_options = {true,false};
    
    while(arg_start_index < argc){
        if(strlen(argv[arg_start_index]) != 2 && argv[arg_start_index][0] != "-"){
            continue;
        }
        
        arg_start_index++;
    }

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