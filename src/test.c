#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "calc.h"
#include "define.h"

START_TEST(arithm_1) {
  char *tmp_s = "2*5+3=";
  double res = 13;
  double p = process_calc(tmp_s);
  ck_assert_double_eq(res, p);
}
END_TEST

START_TEST(arithm_2) {
  char *tmp_s = "2*(5+3)=";
  double res = 16;
  double p = process_calc(tmp_s);
  ck_assert_double_eq(res, p);
}
END_TEST

START_TEST(arithm_3) {
  char *tmp_s = "7-2+5*3=";
  double res = 20;
  double p = process_calc(tmp_s);
  ck_assert_double_eq(res, p);
}
END_TEST

START_TEST(arithm_4) {
  char *tmp_s = "(2*5)+3=";
  double res = 13;
  double p = process_calc(tmp_s);
  ck_assert_double_eq(res, p);
}
END_TEST

START_TEST(arithm_5) {
  char *tmp_s = "-2*5+3*2^4=";
  double res = 38;
  double p = process_calc(tmp_s);
  ck_assert_double_eq(res, p);
}
END_TEST

START_TEST(arithm_6) {
  char *tmp_s = "-2+2*5-3*2^4=";
  double res = -40;
  double p = process_calc(tmp_s);
  ck_assert_double_eq(res, p);
}
END_TEST

START_TEST(arithm_7) {
  char *tmp_s = "-2+2*5+(-3*2^4)=";
  double res = -40;
  double p = process_calc(tmp_s);
  ck_assert_double_eq(res, p);
}
END_TEST

START_TEST(sqrt_1) {
  char *tmp_s = "-sqrt4=";
  double res = -2;
  double p = process_calc(tmp_s);
  ck_assert_double_eq(res, p);
}
END_TEST

Suite *calc_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("CalcTest");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, arithm_1);
  tcase_add_test(tc_core, arithm_2);
  tcase_add_test(tc_core, arithm_3);
  tcase_add_test(tc_core, arithm_4);
  tcase_add_test(tc_core, arithm_5);
  tcase_add_test(tc_core, arithm_6);
  tcase_add_test(tc_core, arithm_7);
  tcase_add_test(tc_core, sqrt_1);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  Suite *s = calc_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}