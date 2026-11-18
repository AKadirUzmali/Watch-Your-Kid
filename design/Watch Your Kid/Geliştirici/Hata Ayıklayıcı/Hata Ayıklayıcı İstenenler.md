+ İstenenler:
	+ Hata ayıklama durumunun aktif olup olmadığını belirlemek
	+ Hata ayıklama türleri belirlemek
	+ Sadece hata ayıklama durumunda çalışacakları belirlemek

	+ Hata ayıklama durumunun aktif olup olmadığını belirlemek:
		+ Hata ayıklama için özel başlık oluşturup, aktif olduğunda hata ayıklamanın aktif olduğunu anlamayı sağlamak:
			+ #__DEBUGGER_TYPE__

	+ Hata ayıklama türleri belirlemek:
		+ Geliştirici hata ayıklama durumu:
			+ #__DEBUGGER_T_DEV__
	
		+ Test hata ayıklama durumu:
			+ #__DEBUGGER_T_TEST__

	+ Sadece hata ayıklama durumunda çalışacakları belirlemek:
		+ Önceden test edilmiş ya da artık test edilmek istenmeyenleri tekrar tekrar test etmek yerine yapıya özel hata ayıklama kodu verip belirtilen durumlarda sadece test edilmelerini sağlamak:
			+ #EXAMPLE #20261112OUTPUTTEST_FRST
			  #DEFINE #__DEBUGGER_CSEL_20261112OUTPUTTEST_FRST
				CSEL = Code Select