# 🌌 Uzay Fiziği Simülasyonu (C Dili)

## 📌 Proje Tanımı

Bu proje, **Algoritmalar ve Programlama** dersi kapsamında (2025–2026 Güz Dönemi) geliştirilmiş,
**konsol tabanlı bir uzay fiziği simülasyonu** uygulamasıdır.

Uygulama tamamen **C programlama dili** kullanılarak yazılmıştır ve herhangi bir grafiksel
arayüz içermemektedir. Tüm kullanıcı etkileşimi terminal (konsol) üzerinden gerçekleştirilmektedir.

Projenin amacı, klasik fizikte yer alan bazı temel deneylerin,
**Güneş Sistemi’ndeki gezegenlerin farklı yerçekimi ivmeleri altında**
nasıl değiştiğini simüle etmektir.

---

## 🧪 İçerilen Deneyler

Program toplam **9 adet fizik deneyini** desteklemektedir.
Her deney **ayrı bir fonksiyon** içerisinde hesaplanmaktadır:

1. Serbest Düşme Deneyi  
2. Yukarı Atış Deneyi  
3. Ağırlık Deneyi  
4. Kütleçekimsel Potansiyel Enerji Deneyi  
5. Hidrostatik Basınç Deneyi  
6. Arşimet Kaldırma Kuvveti Deneyi  
7. Basit Sarkaç Periyodu Deneyi  
8. Sabit İp Gerilmesi Deneyi  
9. Asansör Deneyi  

Her deney seçildiğinde, sonuçlar **tüm gezegenler için ayrı ayrı**
hesaplanarak birimleriyle birlikte ekrana yazdırılır.

---

## 🌍 Gezegenler ve Yerçekimi İvmeleri

Gezegenlerin yerçekimi ivmeleri, Güneş’e olan uzaklığa göre sıralanmış
bir dizi içerisinde tutulmaktadır:

| Gezegen | Yerçekimi (m/s²) |
|-------|------------------|
| Merkür | 3.7 |
| Venüs | 8.87 |
| Dünya | 9.81 |
| Mars | 3.71 |
| Jüpiter | 24.79 |
| Satürn | 10.44 |
| Uranüs | 8.69 |
| Neptün | 11.15 |

⚠️ Dizi elemanlarına erişimde **indis kullanılmamış**, tüm işlemler
**pointer (işaretçi) mantığı** ile gerçekleştirilmiştir.

---

## ⚙️ Teknik Özellikler

- ✔️ C programlama dili ile geliştirilmiştir  
- ✔️ Konsol tabanlıdır (GUI yoktur)  
- ✔️ Modüler yapı (her deney ayrı fonksiyon)  
- ✔️ Gezegen verileri dizilerde tutulur  
- ✔️ Dizilere yalnızca pointer ile erişilir  
- ✔️ Negatif girişler ternary operator ile mutlak değere çevrilir  
- ✔️ Sürekli çalışan menü yapısı vardır  
- ✔️ `-1` girildiğinde program sonlanır  
- ✔️ Tüm çıktılar birimleriyle birlikte verilir  

---

## 🧠 Programın Çalışma Mantığı

1. Program başlatılır  
2. Bilim insanının adı kullanıcıdan alınır  
3. Deney menüsü ekrana yazdırılır  
4. Kullanıcı bir deney seçer  
5. Gerekli metrik değerler girilir  
6. Hesaplamalar tüm gezegenler için yapılır  
7. Sonuçlar konsola yazdırılır  
8. Kullanıcı yeni deney seçebilir veya çıkış yapabilir  

---

## 🛠️ Derleme ve Çalıştırma

### Derleme
```bash
gcc space_simulation.c -o space_simulation -lm
