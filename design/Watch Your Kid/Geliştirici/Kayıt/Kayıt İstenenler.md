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
		+ Kayıt işlemi farklı durumlara ait olabilir bu yüzden durum yapısı ile bunun bir başarı, hata, uyarı, bilgi ya da düz metin olup olmadığını ayırmamızı sağlar
		+ Okunabilirliği ve hata durumlarının ayırt edilmesini sağlayarak daha geliştirici dostu bir yapı sağlamak

	+ Thread Yapısı:
		+ Kayıt işleminin yapıldığı işleme ait bilgiyi almak isteriz bu yüzden Thread yapısından faydalanırız çünkü işlem bilgisini almamızı sağlayacak fonksiyonları sağlar

	+ Function Yapısı:
		+ Kayıt yapılırken hangi fonksiyonun hangi satırında problem olduğunu anlamamızı sağlayacak olan fonksiyon yapısını barındırır, bu yapı fonksiyon yerine eski tarz #define ile de olabilir, fakat genel amaç okunabilirliği arttırmak ve hatanın kaynak noktasını öğrenmeyi sağlamak, hatayı anlamayı sağlamak

	+ Output Yapısı:
		+ Çıktı sadece tek bir yolla yapılmayabilir. Kimi zaman bir konsol çıktısı kimi zaman bir dosya çıktısı ya da anlık programın çalışmasını izleyebilmek için bir gui çıktısı da yapılabilir ya da yeni türler eklenebilir. Bu yapı sayesinde bunları sadece entegre etmek isteyip istemememize göre kayıt yapısı farklılaştırmayı sağlayabiliriz

	+ Asenkron Yapısı:
		+ Aynı anda birden fazla işlem yapılabilir ve aynı anda kayıt etmeyi deneyebilirler fakat ikisi ya da daha fazlası aynı aynda işlem yapmaya çalışacağı için kayıtlar birbirine karışacak ve okunmasını zorlaştıracak ve anlamsızlaştıracak. Fakat asenkron yapı ile bir miktar gecikme dahi olsa okunabilir ve sırayla kayıt yapılabilmesini sağlayarak race-condition (yarış durumu) engellenmiş olur

	+ Ek Bilgi:
		+ Kayıt alınırken o kayıt için özel bir başlık ya da bir mesaj verilebilir ki genelde mesaj verilir çünkü o işlemde ne yapılmak istendiği ya da işlem sonucunu mesaj olarak çıktı vererek aslında olması gereken değer yerine hangi değerin oluştuğunu ve ne yapılması gerektiğini kolaylaştırır ve başlık sayesinde de aynı sonucu ya da değeri çıktı verebilecek diğer kayıtlarla karıştırılmamasını sağlamak için o kayıta özel bir başlık verilmesini sağlar. Fakat mesaj ve başlık da isteğe bağlıdır ama diğer kalan tüm işlemler zorunludur