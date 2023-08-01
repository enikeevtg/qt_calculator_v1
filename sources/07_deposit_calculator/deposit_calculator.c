#include "deposit_calculator.h"

int deposit_calculation(struct deposit_input* pdata, struct deposit_output* presult,
                                          int deposit_type) {
  double key_rate = 0.075;
  int periodicity = pdata->periodicity;
  int term = pdata->term;
  double total = pdata->total_begin;
  double deposit_rate = pdata->deposit_rate;
  double tax_rate = pdata->tax_rate;
  double* replenishments = pdata->replenishments;
  double* withdrawals = pdata->withdrawals;

  int error = VALID_ACCOUNT_BALANCE;
  int accruals_number = term / periodicity;
  double last_earning = 0;
  double earnings = 0;
  for (int i = 1; error == VALID_ACCOUNT_BALANCE && i <= accruals_number; i++) {
    for (int j = i * periodicity - 1; j < i * periodicity; j++) {
        total += replenishments[j] - withdrawals[j + 1];
    }
    if (deposit_type == COMPOUND) total += last_earning;
    double tmp = (double)periodicity / 12.0;
    last_earning = total * deposit_rate / 100.0 * tmp;
    earnings += last_earning;
    if (total < 0.0) error = INVALID_ACCOUNT_BALANCE;
  }

  if (error == VALID_ACCOUNT_BALANCE) {
    presult->tax_amount = 0.0;
    if (earnings > key_rate * 1000000) {
        presult->tax_amount = (earnings - key_rate * 1000000) * tax_rate / 100.0;
    }
    presult->accrued_interest = earnings - presult->tax_amount;
    presult->total_end = total;
  }
  return error;
}
