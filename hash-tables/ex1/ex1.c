#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  for(int i = 0; i < length; i++) {
    LinkedPair *pair = create_pair(i, weights[i]);
    hash_table_insert(ht, pair->key, pair->value);
  }
  for(int j = 0; j < length; j++) {
    char hashValue = hash_table_retrieve(ht, (limit - weights[j]));
    if(hashValue != -1) {
      for(int k = 0; k < length; k++) {
        if(hashValue == weights[k])
          answer->index_1 = k;
      }
      answer->index_2 = j;
    }
    int temp = 0;
    if(answer->index_1 < answer->index_2) {
      temp = answer->index_1;
      answer->index_1 = answer->index_2;
      answer->index_2 = temp;
    }
    return answer;
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}