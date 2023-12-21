getPredict <- function(test_data_transactions, used_rules) {
  temp <- apriori(
    test_data_transactions,
    parameter = list(sup = used_rules@info$support, conf = used_rules@info$confidence),
    appearance = list(lhs = used_rules@lhs@itemsetInfo))
  return (temp)
}

result <- getPredict(test_data_transactions, rules_19)

inspect(result)
