#include <iostream> 
#include <string> 
using namespace std;

class Artikul { //базов клас
protected: 
    string zaglavie; 
    int godina; 

public:
    Artikul(string z = "Nqma", int g = 2000) { //констуктор по подразбиране
        zaglavie = z;
        godina = g;
    }

    virtual ~Artikul() {} //деструктор

    virtual void otpechataiInfo() const = 0; //метод 

    void vzemi() const { cout << "Artikulat e vzet.\n"; } // метод
    void vurni() const { cout << "Artikulat e vurnat.\n"; }
};

class Kniga : public Artikul { //2ниво
protected:
    string avtor;
    int stranici;

public:
    Kniga(string z = "Nqma", int g = 2000, string a = "Nqma", int s = 0) : Artikul(z, g) {
        avtor = a; 
        stranici = s;
    }

    void otpechataiInfo() const override { //прен.мет
        cout << "Kniga: " << zaglavie << ", Avtor: " << avtor << "\n";
    }

    void otvori() const { cout << "Knigata e otvorena.\n"; } // метод
    void zatvori() const { cout << "Knigata e zatvorena.\n"; }
};

class Media : public Artikul {
protected:
    int vremetraene;
    string vid;     

public: 
    Media(string z = "Nqma", int g = 2000, int v = 0, string vd = "Nqma") : Artikul(z, g) {
        vremetraene = v;
        vid = vd;  
    }
    void otpechataiInfo() const override {
        cout << "Media: " << zaglavie << ", Vreme: " << vremetraene << " min\n";
    }
    void pusni() const { cout << "Mediata sviri.\n"; } 
    void spri() const { cout << "Mediata sprq.\n"; } 
};

class Spisanie : public Kniga { //3ниво
protected:
    int broy;
    string izdatel;   

public:
    Spisanie(string z = "N", int g = 2000, string a = "N", int s = 0, int b = 1, string i = "N")
        : Kniga(z, g, a, s) {
        broy = b;      
        izdatel = i;   
    }

    void otpechataiInfo() const override {
        cout << "Spisanie: " << zaglavie << ", Broy: " << broy << "\n";
    }

    void listai() const { cout << "Listam spisanieto.\n"; }
    void hvurli() const { cout << "Spisanieto e hvurleno.\n"; } 
};

class EKniga : public Kniga {
protected: 
    double razmerMB;
    string format;

public: 
    EKniga(string z = "N", int g = 2000, string a = "N", int s = 0, double mb = 1.5, string f = "PDF")
        : Kniga(z, g, a, s) {
        razmerMB = mb;
        format = f;   
    }

    void otpechataiInfo() const override {
        cout << "E-Kniga: " << zaglavie << ", Format: " << format << "\n";
    }

    void iztegli() const { cout << "Failut se tegli.\n"; } 
    void iztriiFail() const { cout << "Failut e iztrit.\n"; } 
};

class DVD : public Media {
protected: 
    bool eHD; 
    int region; 

public:
    DVD(string z = "N", int g = 2000, int v = 0, string vd = "N", bool hd = true, int r = 1)
        : Media(z, g, v, vd) {
        eHD = hd; 
        region = r;
    }
    void otpechataiInfo() const override {
        cout << "DVD: " << zaglavie << ", HD: " << eHD << "\n";
    }

    void zaredi() const { cout << "Diskut zarejda.\n"; }
    void izvadi() const { cout << "Diskut izleze.\n"; } 
};

class BluRay : public DVD { //4
protected:
    bool e4K;   
    string zvuk;

public: 
    BluRay(string z = "N", int g = 2000, int v = 0, string vd = "N", bool hd = true, int r = 1, bool k = true, string zv = "Atmos")
        : DVD(z, g, v, vd, hd, r) {
        e4K = k;    
        zvuk = zv;   
    }

    void otpechataiInfo() const override {
        cout << "BluRay: " << zaglavie << ", Zvuk: " << zvuk << "\n"; 
    }

    void pusni4K() const { cout << "Pusnato v 4K.\n"; } 
    void smeniZvuk() const { cout << "Zvukat e smenen.\n"; } 
};

int main() {

    Artikul* katalog[6];

    katalog[0] = new Kniga("Pod Igoto", 1894, "Vazov", 400); // Обекти
    katalog[1] = new Media("Muzika", 1990, 60, "Audio");
    katalog[2] = new Spisanie("Nat Geo", 2024, "Kolektiv", 50, 12, "NG");
    katalog[3] = new DVD("Matrix", 1999, 136, "Video", true, 2);
    katalog[4] = new BluRay("Dune", 2024, 160, "Video", true, 1, true, "Atmos");
    katalog[5] = new EKniga("C++ Naruchnik", 2023, "Ivanov", 350, 5.5, "EPUB");

    for (int i = 0; i < 6; i++) {
        katalog[i]->otpechataiInfo();
    }

    for (int i = 0; i < 6; i++) {
        delete katalog[i]; // Изтриване обект
    }

}