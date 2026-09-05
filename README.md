# Arduino Music Player

Arduino kullanılarak geliştirilmiş bir müzik oynatıcı projesidir. Proje; buzzer üzerinden melodi çalarken, 16x2 LCD ekranda şarkı sözlerini gösterir ve çalınan notalara göre LED'leri kontrol eder.

## Özellikler

* 🎵 Buzzer kullanarak önceden tanımlanmış melodileri çalma
* 🎶 Farklı nota ve oktavları destekleme
* 📺 16x2 LCD ekranda şarkı sözlerini gösterme
* 💡 Çalınan notalara göre LED'leri kontrol etme
* ⏱️ Nota sürelerini ve tempoyu ayarlama
* 🎼 BPM değerine göre ritim kontrolü
* 📝 Program başladığında şarkı adını gösterme

## Kullanılan Donanımlar

* Arduino
* 16x2 LCD ekran
* Buzzer
* 7 adet LED
* Breadboard
* Jumper kablolar

## Pin Bağlantıları

| Bileşen       | Arduino Pini |
| ------------- | -----------: |
| LCD RS        |           12 |
| LCD E         |           11 |
| LCD D4        |           A0 |
| LCD D5        |           A1 |
| LCD D6        |           A2 |
| LCD D7        |           A3 |
| Nota LED'leri |          2–8 |
| Buzzer        |            9 |

## Nasıl Çalışır?

Program içerisinde müzik notalarının frekansları tanımlanmıştır. Arduino'nun `tone()` fonksiyonu kullanılarak bu frekanslara karşılık gelen sesler buzzer üzerinden oluşturulur.

Bir nota çalındığında, o notaya karşılık gelen LED aktif hale gelir. Aynı anda LCD ekran üzerinde melodinin ilgili bölümüne ait şarkı sözleri gösterilir.

Melodinin temposu BPM değeri kullanılarak belirlenir. Farklı nota süreleri sayesinde melodinin ritmi ve çalma hızı kontrol edilir.

## Kullanılan Teknolojiler

* **Arduino**
* **C/C++**
* **Arduino LiquidCrystal Kütüphanesi**

## Projenin Amacı

Bu proje ile Arduino kullanarak ses, görüntü ve LED kontrolünün birlikte kullanılabileceği bir uygulama geliştirilmesi amaçlanmıştır.

Proje kapsamında;

* Arduino ile buzzer üzerinden ses üretme,
* LCD ekran kullanımı,
* LED kontrolü,
* Müzik notalarının frekanslarını kullanma,
* Nota sürelerini ve tempo değerlerini yönetme

konularında uygulama yapılmıştır.

## Proje Durumu

**Tamamlandı.**

## Geliştirilebilecek Özellikler

* Birden fazla şarkı ekleme
* Butonlarla şarkı seçme
* Ses seviyesini kontrol etme
* Daha fazla nota için LED ekleme
* Menü sistemi oluşturma
* Kullanıcının kendi melodisini oluşturabilmesi

## Geliştirici

**Sude Sena Aydın**
