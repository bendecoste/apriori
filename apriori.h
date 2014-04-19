#ifndef __APRIORI_H_
#define __APRIORI_H_

#include "transaction.h"

typedef struct occurrence {
  int support;
} occurrence;

/*
 * Occurrence table will store an 'occurrence' at each array index (0-9)
 * and when iterating through the transaction list, it will increment each
 * index (which will be an occurrence struct) whenever that number is seen
 */
typedef struct occurr_table {
  struct occurrence *occurr;
} occurr_table;

// iterate over the trans_list and find how many times various numbers happen
struct occurr_table get_occurr_table(struct trans_list t_list);
void occurr_table_increment(struct occurr_table *o_table, int data);

void print_occurr_table(struct occurr_table o_table);

#endif
