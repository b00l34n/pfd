#include <math.h>

#include "../factor_list/factor_list.h"
#include "./prime.h"

/* INTERN */
unsigned char is_prime(uint d){
  if (d % 2 == 0) return 0;
  if (d % 3 == 0) return 0;
  for (uint i = 3; i < d; i += 2){
      if (d % i == 0) return 0;
    }
  return 1;
}

/* EXTERN */
uint get_next_prime(uint current_prime){
  if ((current_prime == 0) || (current_prime == 1)){
    return 2;
  } else {
    if (current_prime == 2){
      return 3;
    } else {
      do current_prime ++;
      while(!is_prime(current_prime));
    }
  }
  return current_prime;
}
