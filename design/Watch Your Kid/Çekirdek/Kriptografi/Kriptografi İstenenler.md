+  İstenenler:
	+ Geleceğe yönelik ve güvenli çalışmayı sağlayan bir kriptografik alt yapı oluşturmak

	+ Geleceğe yönelik ve güvenli çalışmayı sağlayan bir kriptografik alt yapı oluşturmak:
		+ Şifreleme ve şifre çözme fonksiyonları:
			+ encrypt
			+ decrypt
	
		+ Şifreleme için isim ve anahtar belirlemek ve temizlemek:
			+ (set) name
			+ (set) key
			+ (set) clear
	
		+ Şifreleme anahtarı ve isimi için sınır belirlemek:
			+ MIN_LEN_NAME, MAX_LEN_NAME, MIN_LEN_KEY, MAX_LEN_KEY
	
		+ Şifreleme anahtarı ve isminin var olup olmadığının kontrolünü sağlamak:
			+ (has) name
			+ (has) key
	
		+ Şifreleme anahtarı ve isim verisini getirtmek:
			+ (get) name
			+ (get) key
	
		+ Şifreleme anahtarı ve isim değerinin yeni değer olabilmesi için geçerli olup olmadığının kontrolünü sağlamak:
			+ (is) valid_name
			+ (is) valid_key
	
		+ Şifreleme sınıfında hata olup olmadığı bilgisin almak:
			+ (has) error