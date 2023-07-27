/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../smart_calc.h"

/// @brief reverse polish notation expression solving
/// @param q_root queue root pointer
/// @param variable variable value_2
/// @param result result of expression solving
/// @return error code (token_type with invalid argument + 100)
int evaluate_expression(node_t* q_root, double variable, double* result) {
  if (q_root == NULL) return EMPTY_QUEUE;
  int error = OK;
  node_t* s_head = NULL;
  token_t token_type = 0;

  while (!error && q_root) {
    token_type = q_root->token_type;
    if (token_type == NUMBER) {
      error = move_node_from_queue_to_stack(&q_root, &s_head);
    } else if (token_type == VAR) {
      q_root->token_value = variable;
      error = move_node_from_queue_to_stack(&q_root, &s_head);
    } else {
      error = numerical_calculation(&s_head, q_root->token_type);
      remove_head_node(&q_root);
    }
  }
  if (error) {
    remove_struct(&s_head);
    remove_struct(&q_root);
  } else {
    *result = s_head->token_value;
    remove_struct(&s_head);
  }
  return error;
}
