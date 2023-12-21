### LIBRARY YANG DIPAKAI
library(arules)     # machine learning
library(arulesViz)  # ploting
library(plyr)
library(dplyr)
library(readxl)     # pembaca xlsx

### MUAT RAW DATA
# masukkan raw data
#raw_data <- read_xlsx("~/Documents/machine-learning/UAS_ML/transaksi_gabungan.xlsx", skip = 1)

raw_data <- read_xlsx(file.choose(), skip = 1)
raw_data

### PRAPROSES
# salin data set
preprocess <- raw_data
preprocess

# pengecekan keseluruhan
print(preprocess, n = 998)

# Memfilter data yang memiliki kurung di belakang namanya
data_with_bracket <- preprocess[grep("\\(.*\\)", preprocess$ITEM), ]
print(data_with_bracket)

# Menghapus tanda kurung dan isinya dari kolom 'ITEM'
preprocess$ITEM <- gsub("\\(.*\\)", "", preprocess$ITEM)
print(preprocess)

# Mengganti Nama Barang Menjadi Nama atau kategori 
# siapkan diksi yang akan diganti
# pola variable nya adalah pattern_datas["nama setelah diganti"] = "nama sebelum diganti|nama sebelum diganti"
pattern_datas = list()
pattern_datas["Susu"] = "SUSU KENTAL MANIS|DIAMOND STR|OVOMALTINE|Yakult CITRUN|UHT|SUSU|SUSU KENTAL MANI|REAL GOOD|Zee|GREEN SANDS|SUSU DANCOW|ULTRAMILK|SUSU ULTRA|SUSU BENDERA|SUSU INDOMILK|ULTRA STRAWBERRY|SUSU ULTRA|SUSU KENTAL MANIS CARNATION|SUSU UHT|SUSU UHT DIAMOND|SUSU BERUANG|Susu bubuk|SGM|Pediasure|Chil Go!|S26|Enfagrow|Vidoran|Nutrilon|Lactogen|Boneeto|Anmum|BMT|Curcuma Plus|Similac|Morinaga|Friso|Nutribaby|Bebelac|Dancow|Friso Gold|Nutrilon Royal|Lactogen Gold|Anmum Materna|Greenfields|Frisian Flag|Indomilk|Lembang|Ultra Milk|Cap Enaak|Bear Brand|Dancow|HiLo|Milo|Cimory|Milku|Diamond|Ovaltine|Chil.go!|Anchor|Oldenburger|SUSU 250ML|BEAR ORI 189ML|SUSU 200ML|Yakult|SUSU KEDELAI"
pattern_datas["Yoghurt"] = "CIMORY HONEY|YOGURT BLUBERRY|YOGURT|yohurt|Yoghurt|YOGHURT CIMORY|GREEK YOGURT|KBPS YOGHURT PLAIN|SUSU CIMORY|Yoghurt|YOGURT STROBERRY|YOGURT BLUEBERRY"
pattern_datas["Air Mineral"] = "air mineral|Aqua Gelas Dus|AQUA BOTOL|AQUA GALON|AIR GELAS DUS|INFUSED WATER|AIR MINERAL CLEO|AQUA GELAS BOX|PRISTINE BOTOL|AIR KEMASAN BOTOL PRISTINE|AIR CUP AQUA|AIR GALON AQUA|Aqua|Cleo|Club|Le Minerale|Pristine|Equil|Nestle|Nestle Pure Life|Ades|Amidis|AIR MINERAL 750|AIR MINERAL 1500|AIR KEHIDUPAN 1|1L|MICELLAR WATER"
pattern_datas["Kopi"] = "KAPAL API|NESCAFE GOLD|kopi|TOP COFFE|KOPI ABC|LUWAK WHITE KOFFE|KOPI GOODDAY|KOPI KAPAL API|ES Kopi|KOPI SASET|KOPIKO CANDY|NESCAFE|KOPI POCI|KOPIKO WHITE|KOPIKO BLACK|KOPIKO BLEND|KOPIKAP|KOPI GAJAH|KOPI GAJAH (lagi)|KOPIKAPUCCINO|KOPI BUATAN SENDIRI|KOPI SUSU|KOPI TANPA GULA|KOPI CLOVER|KOPI HITAM|INDOCAFE"
pattern_datas["Mie"] = "LEMONILO|PASTA SPAGHETTI|Mie SAMYANG|Mie SEDAAP GORENG|SO'UN|indomie|spageti|Ramen|mie wadah kr|mie|SPAGHETI|SAMYANG|POPMIE|MIE INSTAN|MI INSTAN|BIHUN|BEST WOK MIE|MIE BURUNG DARA|So'unBihun|Mie goreng|mie jumbo|INDOMEI|MIEGHETTI|MIE SEDAP GORENG|BESt WOK MIE|POP MIE|MIE GELAS"
pattern_datas["Saus"] = "SAUS BOLOGNESE|SAOS SAMBEL|SAOS TIRAM|SAOS CABE|SAOS TOMAT|SAUS TOMAT|saus sambel|saus|SAUS TIRAM|SAUS MAKANAN RINGAN|MAYUMI|Sambal ABC|Sambel Indofood|Sambel Boncabe|SAOS ABC|SAUS BULGOGI|SAUS GOCHUJANG|SAUS SAMBAL EXTRA PEDAS ABC|Saos Tomat|Saos Tiram|Saos Cabe|Saos Teriyaki|Saos|Sambal"
pattern_datas["Snack"] = "BRIO POTATO BISCUTIT|NESTAR|TARO|KRIPIK|JAJJANGMYEON|TTEOKBOKI|slai olai|granola|brio potato|chiki|snack|JETZ|OISHI PILLOWS|TWISTKO|FUZO|MAXI CORN|MAICIH|J&J PIATTOS|CEMCEM|GOODTIME|KHONG GUAN|QUAKER|HELLO PANDA|OISHI POPPY|MAITOS|JAPOTA|chic choc|BISKIES|GERY SALUT|OAT BISKUIT|Roma|Milkis|Happy Tos|Potabee|Tar|Keju Cake|Roma Kelapa|KUACI FUZO|MIN-BEE|SPONGE|DORITOS|BETTER|NABATI|CHITATO|QTELA|CRACKERS|SNICKERS|TANGO|TARO BALL|CHOCO PIE|CITATO|MALKIST|KOKO KRUNCH|PRINGLES|LAYS|BENGBENG|OREO|CHEETOS|KUE OREO|ACNES SEALING JELL|BERNARD EASY BITE|BRIO POTATO BISCUIT|SARIRAOS SIMPING|GO POTATO|SUKRO|TIC TAC|SELAI OLAI|SARI GANDUM|HATARI|BISKUIT ROMA|ROMA MALKIST|ROMA|ASTOR|ICHITAN|PRINGLES ORIGINAL|BISKUIT REGAL|MALKIST KEJU|MONDE SNACK|COOKIE|GOOD TIME|SLAI O LAI|OREO|GLICO POCKY|FITBAR|oreoBrio Potato|Keripik|Kit Kat|Stik Keju|ceres|coklat|Popcorn|Wafer|Biskuit|Snack Brownies|Rumput Laut|SNACK BALADO 140|Snack Sapi|Wafle|Gochujang|Tteok|Odeng|BRONDONG JAGUNG"
pattern_datas["Es Krim"] = "KRIM|RAINBOW POWER WALLS|Es Coklat|es coklat|es krim|ESKRIM|AICE|WALLS|KUACI REBO|WALLS ICE CREAM|CORNETTO|CHAMPINA|ES KRIM WALLS|BOBA SUNDAE|STTRAWBERRY LUCKY SUNDAE|CHOCOLATE LUCKY SUNDAE|Ice Cream"
pattern_datas["Manisan"] = "Meses|COKELAT|MANISAN|KOPIKO|POCKY|DAIRY MILK|YUPI LITTLE STARS|COKLAT|alphalibe|marshmallow|agar-agar strawberry|PERMEN|CHACHA|CHUPA CHUPS|YUPI|KITKAT|CADBURY DAIRY MILK|CHOCOLATOS|NYAM-NYAM|COKI-COKI|NUTELLA|MANISAN (YUPI)|PASTA COKLAT|SILVER QUEEN|DELFI CHICCHOC|BOLEN LILIT COKELAT|PUDDING MANGGA|NU CHOCO HAZELNUTEA|RICOLA|DELFI TAKE IT|SILVERQUEEN|DARK CHOCOLATTE|YUPI LITTLE STARS|COKLAT CADBURY|CADBURY|CERES|TOBLERONE|BENG BENG SHARE IT|CHOCOLATOS|RAINBOW POWER WALLS|CORNETO MINI|KINDERJOY|BLASTER|ALPHELIEBE|MENTOS|MENTOS MINT|KOPIKO CANDY|Mentos Candy|Permen karet|Permen|Marshmallow "
pattern_datas["Teh"] = "teh|MY TEA|S-TEE|TEH GELAS|TEH JAVANA|ES teh|TEH BOTOL|TEH CELUP|JAVANA MELATI|TEH SOSRO|Teh Kemasan|MILK TEA|JAVANA"
pattern_datas["Kacang"] = "kacang|MAYASI|SUKRO|NUTS|KACANG ATOM|PILUS GARUDA|KACANG GARUDA|Pilus Garuda|KACANG DUA KELINCI|Kacang Tanah|GARUDA PILUS|GARUDA KACANG"
pattern_datas["Kecap"] = "Kecap Asin|kecap asin|KECAP|KECAP MANIS"
pattern_datas["Obat"] = "SINDE|OBAT NYAMUK|DORA RACUN TIKUS|FOSFOR ANORGANIK|CALCIUM ION|OBAT|GULA DIABET|REPELLANT NYAMUK|OBAT SAKIT KEPALA|HANSAPLAST|PEMBASMI NYAMUK|VAPE|ONE PUSH VAPE|TOLAK ANGIN|VITAMIN D|HEMATOLOGI LENGKAP|REDOXON|AMARYL M 30 TABLET|TOLAK ANGIN|PLESTER|ANTISEPTIK|HAND SANITIZER|BAYGON|VITAMIN|Insektisida|Hand Sanitizer|Kapur Barus|Lotion Anti Nyamuk|Obat Pusing|HIT(Pembunuh Nyamuk)"
pattern_datas["Shampo"] = "PANTENE|shampo|SHAMPOO|VITAMIN RAMBUT|SAMPO CLEAR|SHAMPOO CLEAR|SUNSILK|SHAMPOO REJOYCE|CONDITIONER|HAIR TONIC|Sampo|Garnier|SHAMPOO HEAD & SHOULDER"
pattern_datas["Skincare"] = "GARNIER MEN|PARFUM|KASA STERIL|KAPAS WAJAH|LOTION TUBUH|GARNIER PINK|BODY LOTION|lotion|DEODARAN|cushion|foundation|lipbalm|lip cream|mascara|serum|garnier micellar water|pencuci muka|skincare|WARDAH|POSH MEN|DEODORAN|Shinzui Facial Wash|GARNIER MEN|KRIM ANALGESIK|SABUN CUCI MUKA GARNIER|DAZEL SLS|SABUN CUCI MUKA WARDAH|MASKER WAJAH GARNIER|MOISTURIZER|TONER|MASKER WAJAH|MISCELLAR WATER|KRIM WAJAH|BEDAK TABUR|PELEMBAB WAJAH|LOTION TUBUH|BODY LOTION|MITU WIPE BLUE|GARNIER MICELLAR WATER|Sabun Cuci Muka|SABUN PENCUCI MUKA|SABUN MUKA|SABUN PEMBERSIH MUKA|Handbody|Deodorant|PARFUME|Sunscreen|Liptin|CAT KUKU"
pattern_datas["Sabun"] = " SABUN CUCI PAKAIAN|SABUN CUCI PIRING|SABUN CUCI TANGAN|SABUN MANDI|PEMBERSIH PIRING|SABUN CUCI|SABUN NUVO|Nuvo|BIORE|GIV|SABUN DETOL|SABUN LIFEBUOY|SABUN SCOTCHBRITE|Sabun mandi|SABUN GIV|SABUN MANDI LIFEBOUY"
pattern_datas["Bahan Pokok"] = "MARGARIN|KEJU PRO CHIZ|KUSUKA KEJU BAKAR|SUNCO POUCH|TELUR AYAM NEGERI|KEJU KRAFT|MINYAK GORENG|TEPUNG TERIGU|TELOR|fox|tepung kanji|MADU|KARA|MADU TJ|MAYONAISE|KEJU CRAFT|ROYCO|TELUR|TEPUNG|MINYAK|KOREK GAS|SANTAN|Garam|MADU|BERAS RAMOS|TEPUNG SERBAGUNA|Gas|Toppoki Instan|Sarden ABC SAUS TOMAT|Masako AYAM|MINYAK GORENG FILMA|GULA PASIR|MINYAK GORENG SANIA|Sambal|Tempe|Tahu|PORVITA MARGARIN|MARGARIN BLUEBAND|GULA PUTIH|MAIZENA|LADA BUBUK|BAWANG MERAH|BAWANG PUTIH|BAWANG Daun|BAKING SODA|MERICA|KRAFT CHEEDAR|SEGITIGA BIRU|Beras|Telur Ayam|kornet|Telur Gabus|Keju|Mayonnaise|Sarden|Mentega|Minyak Goreng|Ragi|Gula|KORNET 200G|Tepung Beras|minyak wijen|terigu|Kentang|Bawang|lada Bubuk|minyak goreng|Bon Cabe|minyak Kelapa|Gula Merah|Gula Pasir|TEPUNG"
pattern_datas["Kebutuhan Harian"] = "DAIA|SARDEN ABC SAUS TOMAT|CREAMER|SPONS CUCI PIRING SCOTCH-BRITE|PELEMBUT PAKAIAN DOWNY|PELICIN PAKAIAN KISPRAY|GLAD AOE PEONY|KLINPAK CLING WRAP JUMBO REFFIL|RICH CREME WHIP CREAM POWDER|MINYAK TELON|STELA|PENCUCI PIRING|PEWANGI PAKAIAN|PENGHARUM PAKAIAN|TISU|SABUN PEL LANTAI|penyegar ruangan|pewangi rauangan|PENGHARUM RUANGAN STELLA|PENGHARUM RUANGAN|so klin|sabn cuci piring|cotonbud|pembersih pakaian|penyerap lembab|KERTAS NASI|REFIL PARFUM|PEWANGI SETRIKA|SABUN PEL|DEODIRAN|KAPAS BAYGON|Bon Nori|Mama Lemon|Harpic|Downy|HIT|BLUE BAND|BONCABE|SUNLIGHT|MOLTO|PARFUM AXE|RINSO|SABUN CUCI BAJU|CHEESE CROISSANT|TELUR AYAM NEGERI|TESSA TISSUE|PEMBERSIH LANTAI PORSTEX|PEMUTIH BAYCLIN|SO KLIN LANTAI|HARPIC PEMBERSIH KLOSET|ALAT PEMBERSIH KLOSET|DETERGEN ATTACK|TISSUE PASEO|SPREI|PELEMBUT PAKAIAN|COTTON BUD|Tisu Kering|Stelas|Pewangi Baju|PEMBERSIH LANTAI|TISU BASAH|CUTTONBUD|Pewarna Rambut|Pemutih|PEMUTIH BAYCLIN|Tisu|Tissu|cotton buds|Pewangi Ruangan|Pembersih Pakian|Pembersih Lantai|Sabun Cuci Piring|Pembersih Kamar Mandi|Sabun Cuci Tangan|kamper|Pembersih Mulut|Sikat Botol|Perfume|Detergen|Detergen |DETERGEN RINSO|DETERJEN|Kapur Barus|Tisu|SABUN BAJU|PARFUM BAJU|SPON|Tissue|Kapas|Pewangi Baju|SABUN"
pattern_datas["Kebutuhan Sandang"] = "DAZEL SELIMUT|SEPATU|KAOS KAKI|MASKER|BAJU|CELANA PENDEK|WIG|KACAMATA|SOFTLENS|LENSA KONTAK|CAIRAN SOFTLENS|Celana|Topi|GANTUNGAN BAJU"
pattern_datas["Kebutuhan Umum"] = "KENKO CUTTER| SWALLOW SJD|WAGON CONTAINER BOX|GAJAH TIKUS TRAP|BATERAI ABC|RAJAWALI TS PANJANG LABEL KUNING XL|PLASTIK WRAP|SENDAL|Plastik warp|SPONS CUCI PIRING SCOTCH-BRITE|TRASH BAG|PENSIL FABER CASTELL|PULPEN FABER CASTELL|LAMPU BOHLAM|Kartu|Tiket|Saldo|PRINTER INK|KERTAS|BUKU|PENSIL|PENGHAPUS|Pulpen|Materai|Baterai|PLASTIK|PLASTIK Besar|Kispray|Kuota|Pulsa"
pattern_datas["Pembersih Mulut"] = "ALAT SIKAT GIGI|Pasta Gigi|PASTA GIGI|LISTERINE|Oral-B|Closeup|PEPSODENT|ODOL|SIKAT GIGI FORMULA|PASTA GIGI SENSODYNE|PASTA GIGI CLOSEUP|SIKAT GIGI PEPSODENT|SIKAT|Sikat Gigi|Pasta Gigi|Tusuk Gigi|Alat Sikat Gigi|Pembersih Mulut"
pattern_datas["Kebutuhan Bayi"] = "PASTA BAYI|POPOK|POPOK BAYI|VIDORAN|PROMINA|BEDAK BAYI|DOT BAYI|Pasta Bayi|Snack Bayi|Popok Bayi"
pattern_datas["Kebutuhan Cewe"] = "Pembalut|Softex|Softek"
pattern_datas["Kebutuhan Cowo"] = "Rokok|Bintang|Alat Cukur|alat cukur"
pattern_datas["Makanan"] = "MALANG SARI ASEM|SOSIS HANZEL|CHAMP SOSIS|SOSIS KANZLER|SOZZIZ|FRESTEA|ROTI KAPAS|MAKANAN RINGAN|BATAGOR KUAH|MARTABAK|BATAGOR|ROTI SARIROTI|MATCHA INSTAN|DAGING AYAM|DAGING SAPI|KENTANG GORENG|DUMPLING CEDEA|BAKSO ORI|pizza|dumbling cedea|nasi segitiga mayo|NASI PADANG|KRUPUK|KRIPIKBATAGOR KUAH|AYAM GEPREK|NASI GORENG|CILUNG|SEBLAK|GORENGAN|KEJU PRO CHIZ|FRENCH FRIES|MUJIGAE|FIESTA NUGGET|Prime Bread|SARI KACANG IJO|SUPER BUBUR|ABON|SARI ROTI|BUBUR AYAM INSTAN|FIESTA CHICKEN NUGGET|Baso Urat|Roti Tawar|Seblak Campur|Tofu|KATSU EGG|PKT BREAD.CO|CEDEA SALMON BALL|CEDEA BASO CUMI|CHAMP SOSIS AYAM|CEDEA CHIKUWA|CEDEA STICK KEPITING|CEDEA BASO UDANG|PANGSIT|TAKOYAKI|NUTRIJEL|FISH SNACK WRAP|REGULER NASI|AYAM KRISPY|SPAGHETTI|ROTI TAWAR JUMBO|OATSIDE|AGAR - AGAR SWALLOW|NUGGET AYAM|NORI|KIRANA BASO SKL HIJAU|CEREAL KELLOGG'S|MIEGHETTI|SARIMI|FITBAR|Pangsit|Roti isi|BUBUR SOTO|ROTI SARI ROTI|NESTLE CEREAL|SARI ROTI COKLAT KEJU|Zuppa Soup|Pizaa|Nasi Ayam Betutu|Sup Instan|Cereal|kue|Kentang Goreng|Baso|Nugget|NUGET|Roti|Kue Coklat|Sosis|Donat|Bakso|Makanan Korea|Mie Goreng|Udang|AYAM GORENG|chicken steak|BUBUR AYAM|Ayam|MIE Goreng|Kentang|NASI SEGITA 100G|Baso Ori|Baso Keju|NASI SEGITIGA MAYO (2)|Onigiri|kerupuk|Sereal|Risol Mayo|Sosis Indomaret|Selai Strawberry|Bubur Rasa Ayam|soto Dan Kari|Burger"
pattern_datas["Minuman"] = "CENDOL|ICHITAN THAI MILK TEA|COCA COLA|HYDRA COCO|THE PUCUK|NUTRI SARI|MAMASUKA RUMPUT LAUT|HYDRO COCO|ICHITAN THAI TEA|MINUMAN TEH BOTOL SOSRO|BUAHVITA|SODA LEMON|MINUMAN ISOTONIC|MINUMAN|MARJAN|sprit|air ber-ion|minuman berkarbonasi|MINUMAN ISOTONIK|MINUMAN CINCAU|COKLAT DAN SUSU|COKLAT DAN MINUMAN DINGIN|MINUMAN DINGIN|GOOD MOOD|TEBS|ORANGE WATER|LASEGAR|TARO|TEH TONG JI|EXTRA JOSS|Mogu-Mogu|Nestar|NII GREENTEA|NUTRIBOOST|YOU-C 1000|KRATINGDAENG|BUAVITA|FANTA|ENERGEN|ICHI OCHA|FANTA|SPRITE|FRESSTEA|COCA-COLA|POCARI SWEAT|TEH PUCUK HARUM|PULPY ORANGE|MIZONE|TEMULAWAK|NATA DE COCO|WDANK|BAJIGUR|MINUMAN JUS|MINUMAN JAHE|MINUMAN ION|MINUMAN SODA|Nutrisari|MARJAN COCOPANDAN|YC1000|MINUMAN TEH BOTOL SOSRO|ISOPLUS COCO|TEH TONG TJI|TEH KOTAK|TEH PUCUK HARUM|MINUMAN SPRITE|FRESHTEA JASMINE|MINUMAN PROTEIN|MINERAL WATER KEMASAN BOTOL|Minuman Energi|MOJITO|SODA|LASEGAR|MINUMAN BERSODA|ADEM SARI|OLATTE|ICHITAN THAI MILK TEA|FRUIT TEA APPLE|FF COCONUT TPK|COCO BIT SP GUAVA|Fruit Tea|THAI TEA|Minuman Jeruk|Minuman Isotonic|Minuman Bersoda|Minuman Buah|Sirup|Minuman Kesehatan|Es Buah|Jus Jeruk|Softdrink|Jus|Minuman Energi|Soda|MINUMANA THAILAND|Orange|Bintang|Teh Pucuk|Teh Poci|Larutan Cap Kaki 3|Ademsari"
pattern_datas["Bumbu"] = "MASAKO SAPI|LADAKU MERICA BUBUK|KALDU JAMUR|PENYEDAP|Bumbu TOMYUM|BUBUK AGAR - AGAR|FLA|PENYEDAP RASA|KALDU BUBUK|BUMBU|BAKING POWDER|perasa makanan|masako|bubuk puding|BUMBU INSTAN|BUMBU SASA|BUMBU DAPUR|BUMBU RACIK SAJIKU|Penyedap Rasa|Bumbu Magic|DELMONTE EXTRA HOT PET|LADAKU MERICA BUBUK|Bumbu Nasi Goreng|Bumbu Racik Serbaguna|Bumbu Racik Serbaguna|Bumbu Racik"
pattern_datas["buah"] = "MELON|ANGGUR|buah|JERUK MEDAN|SALAK PONDOH|LYCHEE|PEAR|NANAS|SALAK PONDOH|Buah-Buahan|PISANG|SEMANGKA|Apel Fuji|Apel|Buahvita|Pepaya|Jeruk|Semangka"
pattern_datas["Sayur"] = "BROKOLI|DAUN BAWANG|SAYUR|SAYURAN SEGAR|KENCUR|SELADA|BAWANG BOMBAY|TOMAT|BAYAM|tauge|wortel|timun|kangkung|JAGUNG|DAUN BAWANG|BAWANG BOMBAY|JAMUR INOKITATE|Sawi Putih|Jamur|Kol| BAYAM|Tomat|JAMUR ENOKI|SELAI|PAKCOY|CABAI|Seledri"
pattern_datas["Ikan"] = "Ikan Salmon|Ikan"
pattern_datas["Alat Makan"] = "CUP|Mangkuk|Centong Nasi|SPON|Pisau|Sendok|Garpu|Mangkok|Gelas"
pattern_datas["Alat Mandi"] = "PERALATAN MANDI|HANDUK"
pattern_datas["Alat Rumah"] = " PERALATAN MANDI AIR|CERMIN|KARPET|Tas|Sandal|LAMPU|KURSI|ALAT MASAK"
pattern_datas["Alat sekolah"] = "Pensil|Penggaris|Halaman kertas|Buku|Pensil warna|Krayon"
pattern_datas["Alat Olahraga"] = "Bola|Sepatu olahraga|Raket badminton|RAKET TENIS"
pattern_datas["Makanan hewan"] = "WHISKAS MAKANAN KUCING|Royale"
pattern_datas["Perhiasan"] = "KALUNG|CALUNG"
pattern_datas["Daging"] = "Daging"
pattern_datas["Mainan"] = "mainan"
pattern_datas["elektronik"] = "usb|HARD DRIVE|KABEL HDMI|WEBCAM|BATERAI LAPTOP|KABEL VGA|HEADSET|MOUSE|LAPTOP|SPEAKER|HARD DRIVE|RAM|MONITOR|MOUSE PAD|KEYBOARD|TINTA|BATERAI LAPTOP|MOUSE|ADAPTOR|CCTV|KIPAS LAPTOP|Handphone|KABEL CHARGER|EARPHONE|KABEL CHARGER TYPE C|KABEL USB"

standardization_item_name <- function(pattern_datas, preprocess) {
  # replace nama item sesuai pattern_datas
  for(i in 1:length(pattern_datas)) { # looping data dari 1 sampai sepanjang pattern_datas
    preprocess$ITEM <- gsub(
      pattern=pattern_datas[names(pattern_datas)[i]],
      replacement=names(pattern_datas)[i],
      preprocess$ITEM,
      ignore.case=TRUE
    )
    print(names(pattern_datas)[i])
  }
  
  preprocess$ITEM <- gsub(pattern="Angkot|FILM|ATM|BOLA|RAKET TENIS|Lexus|KOIN", replacement="", preprocess$ITEM, ignore.case=TRUE)
  preprocess$ITEM <- gsub(pattern=",,", replacement="", preprocess$ITEM, ignore.case=TRUE)
  preprocess$ITEM <- gsub(pattern=", ,", replacement="", preprocess$ITEM, ignore.case=TRUE)
  
  # lower case semua data
  preprocess$ITEM <- tolower(preprocess$ITEM)
  
  return (preprocess)
}

pattern_datas = list()
pattern_datas["Alat Kesehatan"] = "KOP"

#Melakukan pergantian pattern_datas
standardization_item_name <- function(pattern_datas, preprocess) {
  # replace nama item sesuai pattern_datas
  for(i in 1:length(pattern_datas)) { # looping data dari 1 sampai sepanjang pattern_datas
    preprocess$ITEM <- gsub(
      pattern=pattern_datas[names(pattern_datas)[i]],
      replacement=names(pattern_datas)[i],
      preprocess$ITEM,
      ignore.case=TRUE
    )
    print(names(pattern_datas)[i])
  }
  
  preprocess$ITEM <- gsub(pattern="Angkot|FILM|ATM|BOLA|RAKET TENIS|Lexus|KOIN", replacement="", preprocess$ITEM, ignore.case=TRUE)
  preprocess$ITEM <- gsub(pattern=",,", replacement="", preprocess$ITEM, ignore.case=TRUE)
  preprocess$ITEM <- gsub(pattern=", ,", replacement="", preprocess$ITEM, ignore.case=TRUE)
  
  # lower case semua data
  preprocess$ITEM <- tolower(preprocess$ITEM)
  
  return (preprocess)
}

preprocess <- standardization_item_name(pattern_datas, preprocess)
preprocess

# tulis kembali data yang telah dipraproses dan baca kembali
# linux
#path_process_data = "~/Documents/machine-learning/UAS_ML/data_transactions_2.csv"

path_process_data = "D:/kuliah upi/SEM 3/ML/uas/data_transactions_3.csv"
create_data_transactions <- function(src_data, path_file) {
  write.csv(
    preprocess,
    path_process_data,
    quote = FALSE,
    row.names = TRUE
  )
  
  data_transactions = read.transactions(
    file = path_process_data,
    rm.duplicates = FALSE,
    format = "basket",
    header = TRUE,
    sep = ",",
    cols = 1,
  )
  
  return (data_transactions)
}

data_transactions = create_data_transactions(preprocess, path_process_data)

# MEMBUAT MODEL dan ploting
# Model 1
rules_1 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.02, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_1, by = "lift"))
plot(sort(rules_1, by = "lift"))

# Model 2
rules_2 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.04, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_2, by = "lift"))
plot(sort(rules_2, by = "lift"))

# Model 3
rules_3 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.08, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_3, by = "lift"))
plot(sort(rules_3, by = "lift"))

# Model 4
rules_4 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_4, by = "lift"))
plot(sort(rules_4, by = "lift"))

# Model 5
rules_5 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.9, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_5, by = "lift"))
plot(sort(rules_5, by = "lift"))

# Model 6
rules_6 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.01, maxtime = 100, target = "rules")
)
summary(sort(rules_6, by = "lift"))
plot(sort(rules_6, by = "lift"))

# Model 7
rules_7 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.001, maxtime = 100, target = "rules")
)
summary(sort(rules_7, by = "lift"))
plot(sort(rules_7, by = "lift"))

# Model 7
rules_7 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.09, maxtime = 100, target = "rules")
)
summary(sort(rules_7, by = "lift"))
plot(sort(rules_7, by = "lift"))

# Model 8
rules_8 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 5, sup = 0.01, conf = 0.1, maxtime = 100, target = "rules")
)
summary(sort(rules_8, by = "lift"))
plot(sort(rules_8, by = "lift"))

# Model 9
rules_9 <- apriori(
  data = data_transactions,
  parameter = list(maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100000, target = "rules")
)
summary(sort(rules_9, by = "lift"))
plot(sort(rules_9, by = "lift"))

# Model 10
rules_10 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 2, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, target = "rules")
)
summary(sort(rules_10, by = "lift"))
plot(sort(rules_10, by = "lift"))

# Model 11
rules_11 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, target = "rules")
)
summary(sort(rules_11, by = "lift"))
plot(sort(rules_11, by = "lift"))

# Model 12
rules_12 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = FALSE, target = "rules")
)
summary(sort(rules_12, by = "lift"))
plot(sort(rules_12, by = "lift"))

# Model 13
rules_13 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 1e-04, maxtime = 100, originalSupport = FALSE, target = "rules")
)
summary(sort(rules_13, by = "lift"))
plot(sort(rules_13, by = "lift"))

# Model 14
rules_14 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(tree = FALSE)
)
summary(sort(rules_14, by = "lift"))
plot(sort(rules_14, by = "lift"))

# Model 15
rules_15 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(tree = FALSE, heap = FALSE)
)
summary(sort(rules_15, by = "lift"))
plot(sort(rules_15, by = "lift"))

# Model 16
rules_16 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(tree = FALSE, heap = FALSE, memopt = TRUE)
)
summary(sort(rules_16, by = "lift"))
plot(sort(rules_16, by = "lift"))

# Model 17
rules_17 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, ext = FALSE, target = "rules"),
  control = list(tree = FALSE, heap = FALSE, memopt = TRUE)
)
summary(sort(rules_17, by = "lift"))
plot(sort(rules_17, by = "lift"))

# Model 18
rules_18 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(filter = 0, tree = FALSE, heap = FALSE, memopt = TRUE)
)
summary(sort(rules_18, by = "lift"))
plot(sort(rules_18, by = "lift"))

# Model 19
rules_19 <- apriori(
  data = data_transactions,
  parameter = list(minlen = 1, maxlen = 100, sup = 0.01, conf = 0.01, maxtime = 100, originalSupport = TRUE, target = "rules"),
  control = list(filter = 1, tree = FALSE, heap = FALSE, memopt = TRUE)
)
summary(sort(rules_19, by = "lift"))
plot(sort(rules_19, by = "lift"))

## sample
small <- sample(data_transactions, 500)
large <- sample(data_transactions, 999)

## cluster a small sample and extract the cluster lael vector
d_jaccard <- dissimilarity(small)
hc <- hclust(d_jaccard)
l <-  cutree(hc, k=4)

## predict labels for a larger sample
labels <- predict(small, large, l)

inspect(labels)

raw_data_2 <- read_xlsx(file.choose())
raw_data_2

preprocess_2 <- raw_data_2
preprocess_2

preprocess_2$`REAL ITEM`<- NULL
preprocess_2$PREDIKSI <- NULL

colnames(preprocess_2) <- c("ITEM")

# replace nama item seperti di atas
preprocess_2 <- standardization_item_name(pattern_datas, preprocess_2)
preprocess_2

#path_process_data_2 = "D:/kuliah upi/SEM 3/ML/uas/Data Testing Transaksi.csv"
#path_process_data_2 = "~/Documents/machine-learning/UAS_ML/Data Testing Transaksi.csv"
path_process_data_2 = "D:/kuliah upi/SEM 3/ML/uas/data_transactions_3.csv"

data_transactions = create_data_transactions(preprocess_2, path_process_data_2)

#Predict recommend
item <- data_transactions
recommend <- subset(rules_9, lhs %in% item)

## cluster a small sample and extract the cluster lael vector
d_jaccard <- dissimilarity(rules_9)
hc <- hclust(d_jaccard)
l <-  cutree(hc, k=4)

## predict labels for a larger sample
labels <- predict(rules_9, new_data, l)


#coba - coba
subset(rules_9, subset = is.element(lhs(rules_9), items(new_data)))

inspect(labels)

d_jaccard_new_data <- dissimilarity(new_data)
l_new_data <- cutree(hc, k = 4)
print(l_new_data)

new_data_subset <- subset(new_data, subset = rules_9)

inspect(new_data_subset)

predictions <- predict(rules_9, newdata = new_data)

inspect(predictions)