### LIBRARY YANG DIPAKAI
library(arules)     # machine learning
library(readxl)     # pembaca xlsx
library(arulesViz)  # ploting

### MUAT RAW DATA
# masukkan raw data
raw_train_data <- read_xlsx("~/Documents/machine-learning/UAS_ML/transaksi_gabungan.xlsx", skip = 1)
raw_train_data

### PRAPROSES
# salin data set
preprocess_train_data <- raw_train_data
preprocess_train_data

# pengecekan keseluruhan
print(preprocess_train_data, n = 998)

# Memfilter data yang memiliki kurung di belakang namanya
data_with_bracket <- preprocess_train_data[grep("\\(.*\\)", preprocess_train_data$ITEM), ]
print(data_with_bracket)

# Menghapus tanda kurung dan isinya dari kolom 'ITEM'
preprocess_train_data$ITEM <- gsub("\\(.*\\)", "", preprocess_train_data$ITEM)
print(preprocess_train_data)
