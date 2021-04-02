#include <stdio.h>
#include <stdlib.h>

#include "factor_list.h"

#define NODE_SIZE (sizeof(char)*(sizeof(uint) + sizeof(pf_node)))

uint nodeCount = 0;


pf_node create_node(){
  nodeCount++;  
  return (pf_node)malloc(NODE_SIZE);
}

pf_node add_new_factor(pf_node node, uint prime){  
  char done = 0;
  pf_node 
    scanning_pointer = node,
    tmp = create_node();
  
  if (tmp == NULL){
    return NULL;
  }

  tmp->prime_number = prime;
  tmp->next = NULL;

  // Wenn liste leer
  if (node == NULL){ 
    return tmp;
  } else {
    // Wenn nur ein element in der liste ist
    if (scanning_pointer->next == NULL){
      if (prime > scanning_pointer->prime_number){
        scanning_pointer->next = tmp;
      } else {
        tmp->next = scanning_pointer;
        return tmp;
      }
    // Wenn die liste länger ist:
    } else {
      // prüfe das erste element
      if (prime < scanning_pointer->prime_number){
        tmp->next = scanning_pointer;
        return tmp;
      } else {
        // Sollange ein nächstes Element da ist und man noch niht fertig ist:
        while((scanning_pointer->next != NULL) && (!done)){
          // wenn die nächste Zahl größer als die neue ist
          if (prime > scanning_pointer->next->prime_number){
            scanning_pointer = scanning_pointer->next;
          } else {
            tmp->next = scanning_pointer->next;
            scanning_pointer->next = tmp;
            done = 1;
          }
        }
        // falls das Neue Lement ganz groß ist:
        if (!done){
          scanning_pointer->next = tmp;
          tmp->next = NULL; 
        }
      }
    }
    return node;
  }
}

void print_prime_factors(pf_node node, uint number){
  pf_node scanning_pointer = node;
  if (node == NULL){
    fprintf(stderr, "%s\n", "ERROR: LIST IS EMPTY");
  } else {
    printf("%d ", scanning_pointer->prime_number);
    scanning_pointer = scanning_pointer->next;
    while (scanning_pointer != NULL){
      printf("* %d ", scanning_pointer->prime_number);
      scanning_pointer = scanning_pointer->next;
    }
    printf("= %d\n", number);
  }
}

void free_list(pf_node node){
  if (node == NULL) return;
  if (node->next != NULL) free_list(node->next);
  free(node);
  nodeCount--;
}

void assure(){
  if (nodeCount > 0) fprintf(stderr,"%d YOU INCOMPETENT FUCK\n", nodeCount);
  else fprintf(stderr,"you did well...\n");  
}
