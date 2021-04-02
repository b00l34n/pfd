
typedef unsigned int uint;

typedef struct prime_factor_list *pf_node;
struct prime_factor_list{
  uint prime_number;
  struct prime_factor_list *next;
};

extern uint nodeCount;

pf_node create_node();

pf_node add_new_factor(pf_node node, uint prime);

void print_prime_factors(pf_node node, uint number);

void free_list(pf_node node);