7-Segment Alarm Clock with 8051 (Proteus)

Main fonksiyonunda seri portu (11.059MHz ve 9600 baud rate) ve seri port için timer 0’ı; saat için timer 1’i (2^16=65.536, 65.536-50.000 ise 50 mikro saniye için) ve timer aktifleştirilmesi (16 bit mod kullandığımız için 8 bitlik ilk kısmı high (/256), 8 bitlik son kısmı low (%256)) ve interrupt aktifleştirilmelerini yaptık.

While kısmında ise alarmımızı kurduk. Alarma izin verildiği takdirde (yani alarm kurulduğunda) sürekli saati kontrol edip, doğruysa bir dakika boyunca alarmı çalıp sonra kapatıyor.

AT89C52 işlemcinin frekans ayarı 11.0598 MHz’dedir. (9600 baud-rate)
Seven Segmentin Common Catode tipi kullanılmıştır.  

Saat bilgisini seven segmente P1 portu ile yolluyoruz.
Bütün segmentleri birbirine bağlayıp, P2 portuyla hangisinin bilgisini göstereceksek o segmentin bacağını 0 yaparak ordaki bilgiyi gönderiyoruz.
Simülasyona başlayınca saatimiz çalışmaya başlıyor.
Virtual Terminal’in yazma ayağını işlemcinin okuma ayağına ve okuma ayağını da yazma ayağına takarak işlemciyle Virtual Terminali bağlıyoruz.
(P3.0 ve P3.1 portları)
Virtual Terminal aracılığı ile alarmı kuruyoruz.
Saat, alarm anına denk gelince P2.7 ayağına bağlı olan ledimiz alarmın çalışını temsil ederek yanıyor ve bir dakika boyunca yanık kalıyor. Ardından sönüyor.
