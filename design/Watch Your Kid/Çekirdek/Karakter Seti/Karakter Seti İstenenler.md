+ İstenenler:
	+ Karakter tür desteği sağlamak
	+ Karakter tür dönüşümü yapabilmek
	+ Metin karakterlerinin çevrimini yapabilmek
	+ Metin karşılaştırması yapmak

	+ Karakter tür desteği sağlamak:
		+ UTF-32 karakter seti desteği
		+ UTF-8 karakter seti desteği

	+ Karakter tür dönüşümü yapabilmek:
		+ UTF-32'den UTF-8'e çevirmek:
			+ to_utf8
			+ from_utf32
	
		+ UTF-8'den UTF-32'ye çevirmek:
			+ to_utf32
			+ from_utf8

	+ Metin karakterlerinin çevrimini yapabilmek:
		+ Karakterleri küçük harfe çevirmek:
			+ to_lowercase
	
		+ Karakterleri büyük harfe çevirmek:
			+ to_uppercase
	
		+ Karakterlerin on altılık (hex) halinin görülmesini sağlamak "\\x":
			+ to_hex

	+ Metin karşılaştırması yapmak:
		+ İki adet utf-32 metini karşılaştırmak:
			+ cmp_utf32
	
		+ İki adet utf-8 metini karşılaştırmak:
			+ cmp_utf8