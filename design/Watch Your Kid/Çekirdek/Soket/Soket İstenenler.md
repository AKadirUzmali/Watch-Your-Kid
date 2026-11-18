+ İstenenler:
	+ Sunucu ve istemci arası iletişimi sağlamak
	+ Sürüm doğrulaması yapmak
	+ Kriptolu veri akışı sağlamak
	+ Belirli sınırlar ve standartlar belirlemek
	+ Hata olmasını engellemek için ön kontroller

	+ Sunucu ve istemci arası iletişimi sağlamak:
		+ Tcp/Ip yapısından faydalanmak
		+ İletişimi handshake sonucu başlatmak
		+ Her işlemde bir gönderen ve bir alıcı olması
		+ Olası hataları bildirmek

	+ Sürüm doğrulaması yapmak:
		+ Sürüm için özel doğrulama anahtarı oluşturmak
		+ Sürüm kontrolü sağlamak

	+ Kriptolu veri akışı sağlamak:
		+ Verilerin giderken ve gelirken kriptolu olup sonradan çözümlenmesini sağlamak
		+ Şifreleme türleri ile farklı iletişim seçenekleri sunmak

	+ Belirli sınırlar ve standartlar belirlemek:
		+ Mesaj, başlık, şifre ve dahasını içeren veri gönderim yapısında her işlenen veriye belirli bir uzunluk sınırı verilmesi:
			+ _MIN_LEN_PASSWORD, _MAX_LEN_PASSWORD, _MIN_LEN_USERNAME, _MAX_LEN_USERNAME, _MIN_LEN_MESSAGE, _MAX_LEN_MESSAGE
	
		+ İstendiğinde iletişimi kesmeyi sağlayacak yapı eklemek:
			+ disconnect
	
		+ Her seferinde port, ip vb. bir sürü bilgi girilmesi yerine oluşturulan özel anahtarın girilmesi ile program tüm bilgileri kendi çözer ve bu sayede bir çok karmaşık bilgi yerine tek bir yazı ile tüm bunlar sağlanır, program ise anahtarı çözümler ve bu sayede işler kullanıcı açısından kolaylaşıp basitleşir:
			+ create_connection_key

	+ Hata olmasını engellemek için ön kontroller:
		+ Verilerin geçerliliğini kontrol etmek:
			+ (is) valid_ipv4
			+ (is) valid_ipv6
			+ (is) valid_ip
			+ (is) valid_port
			+ (is) valid_socket
			+ (is) valid_ipv
	
		+ Limit kontrollerini sağlamak