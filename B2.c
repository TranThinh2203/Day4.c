#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char maSV[10];
    char ten[50];
    char gioiTinh[5];
    float dToan;
    float dLy;
    float dHoa;
    float dtb;
} SinhVien;

void TinhDTB(SinhVien *sv) {
    sv->dtb = (sv->dToan + sv->dLy + sv->dHoa) / 3.0f;
}

void NhapSinhVien(SinhVien *sv) {
    printf("  Ma SV: ");
    scanf("%s", sv->maSV);
    printf("  Ten: ");
    fflush(stdin);
    gets(sv->ten);
    printf("  Gioi tinh (Nam/Nu): ");
    scanf("%s", sv->gioiTinh);
    printf("  Diem Toan: ");
    scanf("%f", &sv->dToan);
    printf("  Diem Ly: ");
    scanf("%f", &sv->dLy);
    printf("  Diem Hoa: ");
    scanf("%f", &sv->dHoa);
    TinhDTB(sv);
}

void XuatSinhVien(SinhVien sv) {
    printf("%-10s %-20s %-8s %5.2f %5.2f %5.2f %5.2f\n",
           sv.maSV, sv.ten, sv.gioiTinh,
           sv.dToan, sv.dLy, sv.dHoa, sv.dtb);
}

void NhapDanhSach(SinhVien ds[], int *n) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        NhapSinhVien(&ds[i]);
    }
}

void XuatDanhSach(SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong.\n");
        return;
    }
    printf("\n--- DANH SACH SINH VIEN ---\n");
    printf("%-10s %-20s %-8s %5s %5s %5s %5s\n",
           "Ma SV", "Ho Ten", "Gioi Tinh", "Toan", "Ly", "Hoa", "DTB");
    for (int i = 0; i < n; i++) {
        XuatSinhVien(ds[i]);
    }
}

void TimMaxGPA(SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong.\n");
        return;
    }
    float maxDTB = ds[0].dtb;
    for (int i = 1; i < n; i++) {
        if (ds[i].dtb > maxDTB) {
            maxDTB = ds[i].dtb;
        }
    }
    printf("\nSinh vien co DTB cao nhat (%.2f diem):\n", maxDTB);
    for (int i = 0; i < n; i++) {
        if (ds[i].dtb == maxDTB) {
            XuatSinhVien(ds[i]);
        }
    }
}

void TimMinGPA(SinhVien ds[], int n) {
    if (n == 0) {
        printf("Danh sach rong.\n");
        return;
    }
    float minDTB = ds[0].dtb;
    for (int i = 1; i < n; i++) {
        if (ds[i].dtb < minDTB) {
            minDTB = ds[i].dtb;
        }
    }
    printf("\nSinh vien co DTB thap nhat (%.2f diem):\n", minDTB);
    for (int i = 0; i < n; i++) {
        if (ds[i].dtb == minDTB) {
            XuatSinhVien(ds[i]);
        }
    }
}

int TimTheoMaSV(SinhVien ds[], int n, const char* maCanTim) {
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maSV, maCanTim) == 0) {
            return i;
        }
    }
    return -1;
}

void TimTheoTen(SinhVien ds[], int n, const char* tenCanTim) {
    int timThay = 0;
    printf("\nSinh vien co ten '%s':\n", tenCanTim);
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ten, tenCanTim) == 0) {
            XuatSinhVien(ds[i]);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay sinh vien nao co ten '%s'.\n", tenCanTim);
    }
}

void HienThiMenu() {
    printf("\n--- MENU (5 CAU DAU) ---\n");
    printf("1. Nhap va xuat thong tin tat ca sinh vien\n");
    printf("2. Xuat sinh vien co diem trung binh cao nhat\n");
    printf("3. Xuat sinh vien co diem trung binh thap nhat\n");
    printf("4. Tim sinh vien co ma sinh vien la '123'\n");
    printf("5. Tim tat ca sinh vien co ten 'Nam'\n");
    printf("0. Thoat\n");
    printf("Lua chon cua ban: ");
}

int main() {
    SinhVien ds[100];
    int n = 0;
    int choice;

    do {
        HienThiMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                NhapDanhSach(ds, &n);
                XuatDanhSach(ds, n);
                break;
            case 2:
                TimMaxGPA(ds, n);
                break;
            case 3:
                TimMinGPA(ds, n);
                break;
            case 4: {
                int index = TimTheoMaSV(ds, n, "123");
                if (index != -1) {
                    printf("Tim thay sinh vien co ma '123':\n");
                    XuatSinhVien(ds[index]);
                } else {
                    printf("Khong tim thay sinh vien co ma '123'.\n");
                }
                break;
            }
            case 5:
                TimTheoTen(ds, n, "Nam");
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}