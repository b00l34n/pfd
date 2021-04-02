#include <stdio.h>

#include "lib/factor_list/factor_list.h"
#include "lib/prime/prime.h"

#define READ_NUMBER (sscanf(argv[1],"%d%c%c", &number, &input_check_dummy0, &input_check_dummy1))

int main(int argc, char const *argv[]){

  /* INIT */
  char 
    input_check_dummy0 = '\0',
    input_check_dummy1 = '\0',
    rtrn = 0;

  uint number = 0,
       trgt_number = 0,
       new_factor = 2;

  pf_node 
    tmp_list = NULL,
    factor_list = NULL;


  /* INPUT CHECK */
  if (argc < 2) {
    fprintf(stderr, "%s\n", "ERROR: GIVE A NUMBER");
    rtrn = 1;
  }
  if (rtrn == 0 && (READ_NUMBER != 1)){
    fprintf(stderr, "%s\n", "ERROR: INPUT IS NOT A NUMBER!");
    rtrn = 1;
  }
  
  if ((rtrn == 0) && ((int)number < 0)) {
    fprintf(stderr, "%d ist keine natürliche Zahl\n", number);
    rtrn = 1;
  }

  /* MAIN CODE */
  if (rtrn == 0){
    trgt_number = number;
    if ((trgt_number == 0) || (trgt_number == 1)){
      printf("%d hat keine Primfactoren\n",trgt_number);
    } else {
      while(trgt_number != 1){
        if ((trgt_number % new_factor) == 0){
          tmp_list = add_new_factor(factor_list, new_factor);
          if (tmp_list != NULL){
            factor_list = tmp_list; 
            trgt_number = trgt_number / new_factor;
            new_factor = 2;
          }else {
            printf("ERROR: LINK LIST BROKE UP!\n");
            return 1;
          }
        } else {
          new_factor = get_next_prime(new_factor);
        }
      }
      print_prime_factors(factor_list,number);
    }
  }

  free_list(factor_list);
  return rtrn;
}