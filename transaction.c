#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "transaction.h"

const int MAX_TRANS_NUM = 4;
const int MAX_ENTRY_NUM = 3;

struct trans_entry new_trans_entry(int *dataset, int size) {
  struct trans_entry *n_trans = malloc(sizeof(struct trans_entry));
  // n_trans->dataset = malloc(sizeof(int) * (sizeof(dataset) / sizeof(dataset[0])));
  n_trans->dataset = dataset;
  n_trans->d_size = size;

  return *n_trans;
}

void print_trans_entry(struct trans_entry t_entry) {
  for (int i = 0; i < t_entry.d_size; ++i) {
    printf("%d, ", t_entry.dataset[i]);
  }

  printf("\n");
}

void add_trans(struct trans_list *t_list, struct trans_entry t_entry) {
  t_list->t_entry[t_list->t_index] = t_entry;
  ++t_list->t_index;
}

void print_trans_list(struct trans_list t_list) {
  for (int i = 0; i < t_list.t_size; ++i) {
    print_trans_entry(t_list.t_entry[i]);
  }

  printf("\n");
}

struct trans_list generate_trans_list(int entries) {
  struct trans_list *t_list = malloc(sizeof(struct trans_list));
  t_list->t_entry = malloc(sizeof(struct trans_entry)*entries);
  t_list->t_size = entries;
  t_list->t_index = 0;

  /*
   * generate an array of a few numbers and pretend that it is a transaction
   */

  srand(time(0));

  for (int i = 0; i < entries; ++i) {
    int num_entries_in_trans = (rand() % MAX_TRANS_NUM) + 1; // no zeros

    int *dataset = malloc(sizeof(int) * num_entries_in_trans);
    for (int j = 0; j < num_entries_in_trans; ++j) {
      int add = ( rand() % MAX_TRANS_NUM ) + 1;
      dataset[j] = add;
    }

    // now that we have created our dataset, put it into an entry, then add
    // that entry into the transaction_list
    trans_entry t_entry = new_trans_entry(dataset, num_entries_in_trans);
    add_trans(t_list, t_entry);
  }

  return *t_list;
}
