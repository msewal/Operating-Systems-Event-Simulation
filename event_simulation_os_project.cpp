#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
#include <algorithm> // std::sort için

using namespace std;

// Olay türlerini tanımlayan enum
enum OlayTuru {
    SurecGeldi,
    SurecCikti,
    SurecCalismayaBasladi,
    SurecCalismayiBirakti,
    SurecGCiIstedi,
    GCBitti,
    OlayTuruSayisi
};

// Olayları temsil eden yapı
struct Olay {
    int zaman;
    OlayTuru tur;
    int surecNo;
};

// Olay adlarını tutan sabit map
const map<OlayTuru, string> olayAdlari = {
    {SurecGeldi, "Surec geldi"},
    {SurecCikti, "Surec cikti"},
    {SurecCalismayaBasladi, "Surec calismaya basladi"},
    {SurecCalismayiBirakti, "Surec calismayi birakti"},
    {SurecGCiIstedi, "Surec GC istedi"},
    {GCBitti, "GC bitti"}
};

// Geçerli olay geçişleri
const map<OlayTuru, vector<OlayTuru>> gecerliOncekiOlaylar = {
    {SurecGeldi, {}},
    {SurecCikti, {SurecGeldi, SurecCalismayiBirakti, GCBitti}},
    {SurecCalismayaBasladi, {SurecGeldi, SurecCalismayiBirakti, GCBitti}},
    {SurecCalismayiBirakti, {SurecCalismayaBasladi}},
    {SurecGCiIstedi, {SurecCalismayaBasladi}},
    {GCBitti, {SurecGCiIstedi}}
};

// Süreçlerin mevcut durumları
map<int, OlayTuru> surecDurumlari;

// Olay adını döndüren fonksiyon
string olayAdiGetir(OlayTuru tur) {
    return olayAdlari.at(tur);  
}

// Olay sırasının geçerliliğini kontrol eden fonksiyon
bool olaySirasiUygunMu(const Olay& yeniOlay) {
    if (surecDurumlari.find(yeniOlay.surecNo) == surecDurumlari.end()) {
        return yeniOlay.tur == SurecGeldi;
    }

    if (gecerliOncekiOlaylar.find(yeniOlay.tur) == gecerliOncekiOlaylar.end()) {
        return false;
    }

    OlayTuru oncekiDurum = surecDurumlari[yeniOlay.surecNo];
    vector<OlayTuru> gecerliOlaylar = gecerliOncekiOlaylar.at(yeniOlay.tur);

    for (OlayTuru gecerliOlay : gecerliOlaylar) {
        if (gecerliOlay == oncekiDurum) {
            return true;
        }
    }

    return false;
}

// Olayı işle ve ekrana yaz
void olayIsle(const Olay& olay) {
    surecDurumlari[olay.surecNo] = olay.tur;
    cout << "zaman: " << setw(3) << setfill('0') << olay.zaman
         << " s: Surec " << olay.surecNo << " " << olayAdiGetir(olay.tur) << "." << '\n';
}

// Olayları zamanlarına göre sıralayan fonksiyon
void siralaOlaylar(vector<Olay>& olaylar) {
    sort(olaylar.begin(), olaylar.end(), [](const Olay& a, const Olay& b) {
        return a.zaman < b.zaman;
    });
}

// Süreçlere ait olayları oluşturan fonksiyon
void olusturSurecOlaylari(vector<Olay>& olaylar, int toplamSurec) {
    int zaman = 1;
    for (int j = 1; j <= toplamSurec; ++j) {
        zaman += rand() % 3 + 1;
        olaylar.push_back({ zaman, SurecGeldi, j });
        olaylar.push_back({ zaman + 1 + rand() % 2, SurecCalismayaBasladi, j });
        olaylar.push_back({ zaman + 3 + rand() % 2, SurecCalismayiBirakti, j });
        olaylar.push_back({ zaman + 5 + rand() % 2, SurecGCiIstedi, j });
        olaylar.push_back({ zaman + 7 + rand() % 2, GCBitti, j });
        olaylar.push_back({ zaman + 9 + rand() % 2, SurecCikti, j });
    }
}

// Ana fonksiyon
int main() {
    srand(time(0));

    vector<Olay> olaylar;
    olusturSurecOlaylari(olaylar, 10);
    siralaOlaylar(olaylar);

    cout << "Simulasyon basladi" << '\n';

    for (const Olay& olay : olaylar) {
        if (olaySirasiUygunMu(olay)) {
            olayIsle(olay);
        }
    }

    return 0;
}
