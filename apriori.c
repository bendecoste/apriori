#include <stdlib.h>
#include <stdio.h>
#include "apriori.h"
#include "transaction.h"

void occurr_table_increment(struct occurr_table *o_table, int data) {
  o_table->occurr[data].support++;
}

struct occurr_table get_occurr_table(struct trans_list t_list) {
  struct occurr_table *o_table = malloc(sizeof(struct occurr_table));
  o_table->occurr = malloc(sizeof(struct occurrence) * 10); // one for each num

  // initialize structure -- set all elements to be zero
  for (int i = 0; i < 10; ++i) {
    o_table->occurr[i].support = 0;
  }

  for (int i = 0; i < t_list.t_size; ++i) {
    struct trans_entry t_entry = t_list.t_entry[i];
    for (int j = 0; j < t_entry.d_size; ++j) {
      occurr_table_increment(o_table, t_entry.dataset[j]);
    }
  }

  return *o_table;
}

void print_occurr_table(struct occurr_table o_table) {
  printf("|ITEM|\t|SUPPORT|\n");
  for (int i = 0; i < 10; ++i) {
    int support = o_table.occurr[i].support;
    printf("{%d}\t%d\n", i, support);
  }

  printf("\n\n");
}
