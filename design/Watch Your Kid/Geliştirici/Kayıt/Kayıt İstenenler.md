+ İstenenler:
	+ Kayıt yapılacak işlemin durumunu belirten bir Durum yapısı
	+ Kayıt işleminin anlık zamanını işleyecek bir Zaman yapısı
	+ Kayıt işleminin hangi işlem (thread) bağlı olduğunu belirtecek bir Thread yapısı
	+ Kayıt işleminin hangi fonksiyon, sınıf vs. ait olduğunu belirtecek bir Function yapısı
	+ Kayıt işleminin çıktısını verileceği yapıların (konsol, dosya, gui) bağlantısının sağlanması, Output yapısı
	+ Kayıt işlemlerinin sırayla yapılmasını sağlayacak Asenkron yapısı
	+ Kayıt ile ilgili başlık ve mesaj depolamak, okunabilirliği arttırmak
	+ Gelecekte sorun yaşamamak için ilk geliştirilmesi gereken yapıdır/yapılardır


	+ Durum Yapısı:
		+ Kayıt için alınan durumun seviyesini belirtmek:
			+ Düz Metin (Plain Text)
			+ Başarı (Success)
			+ Uyarı (Warning)
			+ Hata (Error)
			+ Bilgi (Info)
			+ Test
	
	+ Zaman Yapısı:
		+ Zaman sınıfını sadece içe aktarır ve olan fonksiyonlarını kullanır, kendisi ek bir kayıt zamanlayıcısı oluşturmaz

	+ Thread Yapısı:
		+ Kayıt yapılırken sadece tek tek sırayla yapıp zaman ve maliyet zararı yerine çoklu kayıt yapabilmek için thread yapısını kullanmak

	+ Function Yapısı:
		+ Kayıt yapılırken hata ayıklamayı kolaylaştırmak için fonksiyon bilgilerine erişmeyi sağlar

	+ Output Yapısı:
		+ Kayıt yapılırken dışarı çıktıyı vermeyi ve programı okumayı sağlar

	+ Asenkron Yapısı:
		+ Kayıt yapılırken işlemlerin üst üste yığılıp aynı anda işlem yapmaya çalışmasını engeller

	+ Ek Bilgi:
		+ Kayıt sistemi için geliştirilmiş ve genel kullanımı kayıt sisteminin kullanılabilirliğini arttırmayı sağlar