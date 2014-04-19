#include <stdlib.h>
#include <stdio.h>
#include "transaction.h"
#include "apriori.h"

int main() {
  struct trans_list t_list = generate_trans_list(8);
  print_trans_list(t_list);

  struct occurr_table o_table = get_occurr_table(t_list);
  print_occurr_table(o_table);

  return EXIT_SUCCESS;
}
