#include "deposit_calculator.h"

struct deposit_output deposit_calculation(/*struct deposit_input* pdata,
                                          int deposit_type*/) {
  double total_begin = 1000000.0;
  double total = total_begin;
  int term = 3;
  double deposit_rate = 6.0;
  double tax_rate = 13.0;
  int periodicity = 1;
  double replenishments[4] = {0.0, 1000.0, 2000.0, 3000.0};
  double withdrawals[3] = {500.0, 600.0, 700.0};
  int deposit_type = SIMPLE;

  struct deposit_output result = {0};
  double earnings[4] = {0};

  int error = VALID_ACCOUNT_BALANCE;
  for (int i = 1; error == VALID_ACCOUNT_BALANCE && i <= term; i += periodicity) {
    total += replenishments[i - 1] - withdrawals[i - 1];
    if (deposit_type == CAPITALIZATION) total += earnings[i - 1];
    earnings[i] = total * deposit_rate / 100.0 * (double)periodicity / 12.0;
    if (total < 0.0) error = INVALID_ACCOUNT_BALANCE;
  }  

  if (error == VALID_ACCOUNT_BALANCE) {
    result.tax_amount = (total - total_begin) * tax_rate / 100.0;
    result.accrued_interest = total - total_begin - result.tax_amount;
    result.total_end = total;
  }

  return result;
}
