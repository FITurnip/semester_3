# tulis kembali data yang telah dipraproses dan baca kembali
# linux
path_process_train_data = "~/Documents/machine-learning/UAS_ML/data_transactions_2.csv"
# windows

create_data_transactions <- function(src_data, path_file) {
  write.csv(
    src_data,
    path_file,
    quote = FALSE,
    row.names = TRUE
  )

  data_transactions = read.transactions(
    file = path_file,
    rm.duplicates = FALSE,
    format = "basket",
    header = TRUE,
    sep = ",",
    cols = 1,
  )

  return (data_transactions)
}

train_data_transactions = create_data_transactions(preprocess_train_data, path_process_train_data)
