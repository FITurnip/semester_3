# MEMBUAT MODEL dan ploting
# Model 1
rules_1 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.02, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_1, by = "lift"))
plot(sort(rules_1, by = "lift"))

# Model 2
rules_2 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.021, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_2, by = "lift"))
plot(sort(rules_2, by = "lift"))

# Model 3
rules_3 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.025, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_3, by = "lift"))
plot(sort(rules_3, by = "lift"))

# Model 4
rules_4 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.028, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_4, by = "lift"))
plot(sort(rules_4, by = "lift"))

# Model 5
rules_5 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.03, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_5, by = "lift"))
plot(sort(rules_5, by = "lift"))

# Model 6
rules_6 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.04, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_6, by = "lift"))
plot(sort(rules_6, by = "lift"))

# Model 7
rules_7 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.045, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_7, by = "lift"))
plot(sort(rules_7, by = "lift"))

# Model 8
rules_8 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.049, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_2, by = "lift"))
plot(sort(rules_2, by = "lift"))

# Model 9
rules_9 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.08, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_9, by = "lift"))
plot(sort(rules_9, by = "lift"))

# Model 10
rules_10 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_10, by = "lift"))
plot(sort(rules_10, by = "lift"))

# Model 11
rules_11 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.013, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_11, by = "lift"))
plot(sort(rules_11, by = "lift"))

# Model 12
rules_12 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.018, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_12, by = "lift"))
plot(sort(rules_12, by = "lift"))

# Model 13
rules_13 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.019, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_13, by = "lift"))
plot(sort(rules_13, by = "lift"))

# Model 14
rules_14 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.9, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_14, by = "lift"))
plot(sort(rules_14, by = "lift"))

# Model 15
rules_15 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.01, maxtime = 100, target = "rules")
)
summary(sort(rules_15, by = "lift"))
plot(sort(rules_15, by = "lift"))

# Model 16
rules_16 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.001, maxtime = 100, target = "rules")
)
summary(sort(rules_16, by = "lift"))
plot(sort(rules_16, by = "lift"))

# Model 17
rules_17 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.09, maxtime = 100, target = "rules")
)
summary(sort(rules_17, by = "lift"))
plot(sort(rules_17, by = "lift"))

# Model 18
rules_18 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_18, by = "lift"))
plot(sort(rules_18, by = "lift"))

# Model 19
rules_19 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100000, target = "rules")
)
summary(sort(rules_19, by = "lift"))
plot(sort(rules_19, by = "lift"))

# Model 20
rules_20 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 100, sup = 0.01, conf = 0.011, maxtime = 100000, target = "rules")
)
summary(sort(rules_20, by = "lift"))
plot(sort(rules_20, by = "lift"))

# Model 21
rules_21 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 100, sup = 0.01, conf = 0.012, maxtime = 100000, target = "rules")
)
summary(sort(rules_21, by = "lift"))
plot(sort(rules_21, by = "lift"))

# Model 22
rules_22 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 100, sup = 0.01, conf = 0.013, maxtime = 100000, target = "rules")
)
summary(sort(rules_22, by = "lift"))
plot(sort(rules_22, by = "lift"))

# Model 23
rules_23 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 100, sup = 0.01, conf = 0.014, maxtime = 100000, target = "rules")
)
summary(sort(rules_23, by = "lift"))
plot(sort(rules_23, by = "lift"))

# Model 24
rules_24 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 100, sup = 0.01, conf = 0.016, maxtime = 100000, target = "rules")
)
summary(sort(rules_24, by = "lift"))
plot(sort(rules_24, by = "lift"))

# Model 25
rules_25 <- apriori(
  data = train_data_transactions,
  parameter = list(maxlen = 100, sup = 0.01, conf = 0.018, maxtime = 100000, target = "rules")
)
summary(sort(rules_25, by = "lift"))
plot(sort(rules_25, by = "lift"))

# Model 26
rules_26 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 2, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, target = "rules")
)
summary(sort(rules_26, by = "lift"))
plot(sort(rules_26, by = "lift"))

# Model 27
rules_27 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, target = "rules")
)
summary(sort(rules_27, by = "lift"))
plot(sort(rules_27, by = "lift"))

# Model 28
rules_28 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = FALSE, target = "rules")
)
summary(sort(rules_28, by = "lift"))
plot(sort(rules_28, by = "lift"))

# Model 29
rules_29 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 1e-04, maxtime = 100, originalSupport = FALSE, target = "rules")
)
summary(sort(rules_29, by = "lift"))
plot(sort(rules_29, by = "lift"))

# Model 30
rules_30 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(tree = FALSE)
)
summary(sort(rules_30, by = "lift"))
plot(sort(rules_30, by = "lift"))

# Model 31
rules_31 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(tree = FALSE, heap = FALSE)
)
summary(sort(rules_31, by = "lift"))
plot(sort(rules_31, by = "lift"))

# Model 32
rules_32 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(tree = FALSE, heap = FALSE, memopt = TRUE)
)
summary(sort(rules_32, by = "lift"))
plot(sort(rules_32, by = "lift"))

# Model 33
rules_33 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, ext = FALSE, target = "rules"),
  control = list(tree = FALSE, heap = FALSE, memopt = TRUE)
)
summary(sort(rules_33, by = "lift"))
plot(sort(rules_33, by = "lift"))

# Model 34
rules_34 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(filter = 0, tree = FALSE, heap = FALSE, memopt = TRUE)
)
summary(sort(rules_34, by = "lift"))
plot(sort(rules_34, by = "lift"))

# Model 35
rules_35 <- apriori(
  data = train_data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(filter = 1, tree = FALSE, heap = FALSE, memopt = TRUE)
)
summary(sort(rules_35, by = "lift"))
plot(sort(rules_35, by = "lift"))
