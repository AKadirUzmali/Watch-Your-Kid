+ İstenenler:
	+ Çökme ayarlaması, oluşması durumunda yapılacakları belirlemek

	+ Çökme ayarlaması, oluşması durumunda yapılacakları belirlemek:
		+ Hangi çökme durumlarının kontrol edileceğini belirlemek:
			+ SIGSEGV, SIGABRT, SIGFPE, SIGILL, SIGTERM, SIGINT
	
		+ Çökme öncesi ayarlamaları yapmak:
			+ (init) handler
			+ (set) register
			+ (set) unregister
	
		+ Çökme durumunda ne yapılacağını belirleyen fonksiyon sağlamak:
			+ handler
	
		+ Çökme olması durumunun bilgisini almak veya çökme durumu kontrolü sağlamak:
			+ (has) signal
			+ (get) signal
	
		+ Özelleştirilmiş çökme durumu imkanı sunmak:
			+ oncrash