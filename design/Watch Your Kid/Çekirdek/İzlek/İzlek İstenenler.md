+ İstenenler:
	+ İşlemleri tek çekirdekte yığın yapmak yerine diğer çekirdeklere de yaymasını sağlamak
	+ İşlemlerin sistem tarafından verilen özel #id sinin yanıda program da özel bir iş id'si verecek ve bu sayede istendiği durumda direk o id ile işlem sonlandırılabilecek fakat eğer genel bir iş ise #id bilgisi hep 0 olacak bu sayede işlem sadece sonlanınca sona erecek
	+ İşlemlerin tutulduğu bir havuz yapısı olacak, bu havuzdan seçilen işlem istenildiğinde sonlandırılabilecek

	+ İşlemleri tek çekirdekte yığın yapmak yerine diğer çekirdeklere de yaymasını sağlamak:
		+ Programın tek çekirdeğe yük bindirmesi gecikme ve iş yükünü arttırır, bunu engellemek amaçlı yapılır
		+ İşlemin çalışıp çalışmadığının bilgisini alır
		+ İşlem oluştuktan sonra havuza eklenir

	+ İşlemlerin sistem tarafından verilen özel #id sinin yanıda program da özel bir iş #id si verecek ve bu sayede istendiği durumda direk o #id ile işlem sonlandırılabilecek fakat eğer genel bir iş ise #id bilgisi hep "0" olacak bu sayede işlem sadece sonlanınca sona erecek:
		+ Her işleme işletim sistemi özel bir #id verir zaten fakat yeni bir #id ile istenildiği durumda sonlandırılabilmesini kolaylaştıracağız
		+ O #id bilgisinde işlem yoksa eğer olmadığına dair bilgi döndürecek ya da eğer #id "0" ise genel işlem olduğuna dair bilgi döndürecek ama hiç genel işlem yoksa genel işlem yok diye bilgi döndürecek

	+ İşlemlerin tutulduğu bir havuz yapısı olacak, bu havuzdan seçilen işlem istenildiğinde sonlandırılabilecek:
		+ İşlemlerin kaç tane olduğunun bilgisini veriri
		+ Havuzdan seçilen işlem durdurulabilir, kapatılabilir ya da başka işlemler yapılabilir
		+ Yeni işlem havuza eklenir, iş bitince ise havuzdan silinir
		+ Çökme gibi durumlarda ise kendisini durdurur ve havuzdan temizler