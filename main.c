#include <stdio.h>
#include <math.h>

#define GEZEGEN_SAYISI 8
#define PI 3.14159265359

/* Gezegen isimleri */
const char *gezegenler[GEZEGEN_SAYISI] = {
    "Merkur", "Venus", "Dunya", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptun"
};

/* Yerçekimi ivmeleri (m/s^2) */
double yercekimi[GEZEGEN_SAYISI] = {
    3.7, 8.87, 9.81, 3.71,
    24.79, 10.44, 8.69, 11.15
};

/* 1. Serbest Düşme Deneyi */
void serbestDusme(double *g) {
    double t;
    printf("Sureyi saniye cinsinden giriniz: ");
    scanf("%lf", &t);
    t = (t < 0) ? -t : t;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double h = 0.5 * (*(g+i)) * t * t;
        printf("%s icin alinan yol: %.2lf metre\n", gezegenler[i], h);
    }
}

/* 2. Yukari Atis Deneyi */
void yukariAtis(double *g) {
    double v0;
    printf("Baslangic hizini (m/s) giriniz: ");
    scanf("%lf", &v0);
    v0 = (v0 < 0) ? -v0 : v0;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double hmax = (v0 * v0) / (2 * (*(g+i)));
        printf("%s icin maksimum yukseklik: %.2lf metre\n", gezegenler[i], hmax);
    }
}

/* 3. Agirlik Deneyi */
void agirlik(double *g) {
    double m;
    printf("Kutleyi kg cinsinden giriniz: ");
    scanf("%lf", &m);
    m = (m < 0) ? -m : m;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double G = m * (*(g+i));
        printf("%s icin agirlik: %.2lf Newton\n", gezegenler[i], G);
    }
}

/* 4. Potansiyel Enerji */
void potansiyelEnerji(double *g) {
    double m, h;
    printf("Kutleyi (kg): ");
    scanf("%lf", &m);
    printf("Yuksekligi (m): ");
    scanf("%lf", &h);

    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double Ep = m * (*(g+i)) * h;
        printf("%s icin potansiyel enerji: %.2lf Joule\n", gezegenler[i], Ep);
    }
}

/* 5. Hidrostatik Basinç */
void hidrostatikBasinc(double *g) {
    double rho, h;
    printf("Sivi yogunlugu (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Derinlik (m): ");
    scanf("%lf", &h);

    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double P = rho * (*(g+i)) * h;
        printf("%s icin hidrostatik basinc: %.2lf Pascal\n", gezegenler[i], P);
    }
}

/* 6. Arsimet Kuvveti */
void arsimet(double *g) {
    double rho, V;
    printf("Sivi yogunlugu (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Batan hacim (m^3): ");
    scanf("%lf", &V);

    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double Fk = rho * (*(g+i)) * V;
        printf("%s icin kaldirma kuvveti: %.2lf Newton\n", gezegenler[i], Fk);
    }
}

/* 7. Basit Sarkac */
void sarkac(double *g) {
    double L;
    printf("Sarkac uzunlugu (m): ");
    scanf("%lf", &L);
    L = (L < 0) ? -L : L;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double T = 2 * PI * sqrt(L / (*(g+i)));
        printf("%s icin periyot: %.2lf saniye\n", gezegenler[i], T);
    }
}

/* 8. Ip Gerilmesi */
void ipGerilme(double *g) {
    double m;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = (m < 0) ? -m : m;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double T = m * (*(g+i));
        printf("%s icin ip gerilmesi: %.2lf Newton\n", gezegenler[i], T);
    }
}

/* 9. Asansor Deneyi */
void asansor(double *g) {
    double m, a;
    int yon;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Asansor ivmesi (m/s^2): ");
    scanf("%lf", &a);
    printf("1: Yukari ivmelenme, 2: Asagi ivmelenme: ");
    scanf("%d", &yon);

    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    for(int i = 0; i < GEZEGEN_SAYISI; i++) {
        double N = (yon == 1) ? m * ((*(g+i)) + a) : m * ((*(g+i)) - a);
        printf("%s icin hissedilen agirlik: %.2lf Newton\n", gezegenler[i], N);
    }
}

int main() {
    char bilimInsani[50];
    int secim;

    printf("Bilim insani adini giriniz: ");
    scanf("%s", bilimInsani);

    while(1) {
        printf("\n--- %s'nin Uzay Deneyleri ---\n", bilimInsani);
        printf("1- Serbest Dusme\n");
        printf("2- Yukari Atis\n");
        printf("3- Agirlik\n");
        printf("4- Potansiyel Enerji\n");
        printf("5- Hidrostatik Basinc\n");
        printf("6- Arsimet Kuvveti\n");
        printf("7- Basit Sarkac\n");
        printf("8- Ip Gerilmesi\n");
        printf("9- Asansor\n");
        printf("-1- Cikis\n");
        printf("Seciminizi giriniz: ");
        scanf("%d", &secim);

        if(secim == -1) break;

        switch(secim) {
            case 1: serbestDusme(yercekimi); break;
            case 2: yukariAtis(yercekimi); break;
            case 3: agirlik(yercekimi); break;
            case 4: potansiyelEnerji(yercekimi); break;
            case 5: hidrostatikBasinc(yercekimi); break;
            case 6: arsimet(yercekimi); break;
            case 7: sarkac(yercekimi); break;
            case 8: ipGerilme(yercekimi); break;
            case 9: asansor(yercekimi); break;
            default: printf("Gecersiz secim!\n");
        }
    }

    printf("Program sonlandirildi.\n");
    return 0;
}
