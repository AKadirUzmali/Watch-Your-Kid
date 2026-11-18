+ İstenenler:
	+ Sistem donanımı hakkında bilgi alabilmek
	+ Sistem internete bağlandığı url adresleri bilgilerini alabilmek
	+ Sistem de yapılması istenilen komutları çalıştırabilmek

	+ Donanım Bilgileri:
		+ İşletim sistemi hakkındaki tüm bilgiler:
			+ (get) arch
			+ (get) name
			+ (get) ver
	
		+ Anakart bilgisi:
			+ (get) name
			+ (get) ver
			+ (get) pcie_ver
			+ (get) max_ram
			+ (get) tpm_ver
			+ (get) temperature
			+ (is) secure_boot
	
		+ İşlemci (cpu) bilgisi:
			+ (get) arch
			+ (get) family
			+ (get) name
			+ (get) ghz
			+ (get) max_ghz
			+ (get) max_ram
			+ (get) pcie_ver
			+ (get) socket_type
			+ (get) temperature
	
		+ Ram bilgisi:
			+ (get) size
			+ (get) mhz
			+ (get) latency
			+ (get) name
			+ (get) temperature
	
		+ Ekran kartı (gpu) bilgisi:
			+ (get) name
			+ (get) vram_size
			+ (get) vram_type
			+ (get) pwatt
			+ (get) bios_ver
			+ (get) mhz
			+ (get) directx_ver
			+ (get) temperature
			+ (get) ver
	
		+ Disk bilgisi:
			+ (get) name
			+ (get) index
			+ (get) type
			+ (get) size
			+ (get) health
			+ (get) speed
			+ (get) free_space
			+ (get) used_space
			+ (get) socket_type
			+ (get) temperature

	+ İnternet Bilgileri:
		+ Bağlantı sağlanan url bilgileri:
			+ (get) url
			+ (get) http_ver
			+ (is) secure
	
		+ İnternet (Ethernet) kartı bilgileri:
			+ (get) name
			+ (get) ver
			+ (get) max_speed
	
		+ İnternet bağlantı durumu bilgileri:
			+ (is) active
	
		+ İnternet anlık veri akışı yapılan adreslerin bilgileri:
			+ (get) url
			+ (get) http
			+ (get) data_size
			+ (is) secure

	+ Komut Bilgileri: 
		+ Çalıştırılabilir komut listesi:
			+ (get) executables
	
		+ İşletim sistemine uygun ayarlanmış komutlar:
			+ (get) commands_for_os
	
		+ Komut için gerekli yetki seviyesi:
			+ (get) perm_lvl
			+ (get) curr_perm_lvl
	
		+ Komut çalışma durumu kontrolü ve sonucu:
			+ (is) exec
			+ (is) run