#ifndef SMARTCALC_06_DEPOSIT_CALCULATOR_CREDIT_CALCULATOR_H_
#define SMARTCALC_06_DEPOSIT_CALCULATOR_CREDIT_CALCULATOR_H_

#include <math.h>

enum { SIMPLE, CAPITALIZATION };

#define VALID_ACCOUNT_BALANCE 0
#define INVALID_ACCOUNT_BALANCE 1

struct deposit_input {
  int term;
  int periodicity;
  double total_begin;
  double deposit_rate;  // in percentages
  double tax_rate;
  double* replenishments;
  double* withdrawals;
};

struct deposit_output {
  double accrued_interest;
  double tax_amount;
  double total_end;
};

struct deposit_output deposit_calculation(/*struct deposit_input* pdata,
                                          int deposit_type*/);

#endif  // SMARTCALC_06_DEPOSIT_CALCULATOR_CREDIT_CALCULATOR_H_
