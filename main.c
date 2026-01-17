#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct Options {
  bool print_newline;
  bool interpret_escapes;
};

int main(int argc, char **argv) {
  int arg_start_index = 1;
  struct Options options = {true, false};

  while (arg_start_index < argc) {
    // I am making assumptions that options can only be 2 chars
    if (strlen(argv[arg_start_index]) < 2 && argv[arg_start_index][0] != '-') {
      arg_start_index++;
      continue;
    }

    // Using normal if statements here
    // since i think all these flags can all exsit at once
    // like echo something -e -n ...
    // i will read the original source code toknow more
    if (argv[arg_start_index][1] == 'n') {
      options.print_newline = true;
    }

    if (argv[arg_start_index][1] == 'e') {
      options.interpret_escapes = true;
    }

    if (argv[arg_start_index][1] == 'E') {
      options.interpret_escapes = false;
    }

    arg_start_index++;
  }

  for (int i = 1; i < argc; i++) {
    write(1, argv[i], strlen(argv[i]));

    if (i < argc - 1) {
      write(1, " ", 1);
    }
  }

  if (options.print_newline) {
    write(1, "\n", 1);
  }
  return 0;
}
