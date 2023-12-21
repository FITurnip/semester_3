preprocess_test_data <- raw_test_data
preprocess_test_data

preprocess_test_data$`REAL ITEM`<- NULL
preprocess_test_data$PREDIKSI <- NULL

colnames(preprocess_test_data) <- c("ITEM")

# replace nama item seperti di atas
preprocess_test_data <- standardization_item_name(pattern_datas, preprocess_test_data)
preprocess_test_data
