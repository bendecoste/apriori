#include <stdlib.h>
#include <stdio.h>
#include "transaction.h"

int main() {
  struct trans_list t_list = generate_trans_list(8);
  print_trans_list(t_list);

  return EXIT_SUCCESS;
}
