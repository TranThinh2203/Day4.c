#include <stdio.h>
#include <math.h>

typedef struct 
{
    int tu;
    int mau;
} Phanso;

int Uoc_chung(int a, int b)
{
    a = ttd(a);
    b = ttd(b);
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;

}

void RG(Phanso *ps) {
    if (ps->mau < 0)
    {
        ps->tu = -ps->tu;
        ps->mau = -ps->mau;
    }
    int uc = Uoc_chung(ps->tu, ps->mau);
    ps->tu /= uc;
    ps->mau /= uc;
}

void NhapPhanSo(Phanso *ps, char ten) {
    printf("Nhap phan so %c:\n", ten);
    printf("Tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Mau so (khac 0): ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

void XuatPhanSo(Phanso ps, char* ten) {
    RutGon(&ps);
    printf("%s", ten);
    if (ps.mau == 1 || ps.tu == 0) {
        printf("%d\n", ps.tu);
    } else {
        printf("%d/%d\n", ps.tu, ps.mau);
    }
}

Phanso Cong(Phanso ps1, Phanso ps2) {
    Phanso ketQua;
    ketQua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    RutGon(&ketQua);
    return ketQua;
}

Phanso Tru(Phanso ps1, Phanso ps2) {
    Phanso ketQua;
    ketQua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    RutGon(&ketQua);
    return ketQua;
}

Phanso Nhan(Phanso ps1, Phanso ps2) {
    Phanso ketQua;
    ketQua.tu = ps1.tu * ps2.tu;
    ketQua.mau = ps1.mau * ps2.mau;
    RutGon(&ketQua);
    return ketQua;
}

Phanso Chia(Phanso ps1, Phanso ps2) {
    Phanso ketQua;
    ketQua.tu = ps1.tu * ps2.mau;
    ketQua.mau = ps1.mau * ps2.tu;
    
    if (ketQua.mau == 0) {
        printf("Loi: Chia cho 0!\n");
        ketQua.tu = 0; 
        ketQua.mau = 1; 
    } else {
        RutGon(&ketQua);
    }
    return ketQua;
}

int main() {
    Phanso a, b;

    NhapPhanSo(&a, 'A');
    NhapPhanSo(&b, 'B');

    printf("KET QUA");
    
    XuatPhanSo(a, "Phan so A = ");
    XuatPhanSo(b, "Phan so B = ");

    Phanso tong = Cong(a, b);
    XuatPhanSo(tong, "A + B = ");

    Phanso hieu = Tru(a, b);
    XuatPhanSo(hieu, "A - B = ");

    Phanso tich = Nhan(a, b);
    XuatPhanSo(tich, "A * B = ");

    if (b.tu == 0) {
        printf("Khong thuc hien duoc phep chia A / B do B = 0.\n");
    } else {
        Phanso thuong = Chia(a, b);
        XuatPhanSo(thuong, "A / B = ");
    }

    return 0;
}