#include <iostream>
using namespace std;
struct HoaDon
{
    char maKH;
    string hoTenKH;
    string diaChi;
    char dienthoai;
    int tieuthuKW[4];
    int dongia[4];
    int gtgt;
    int tongtien;
    int thanhtien[4];
    HoaDon *next;
};
HoaDon *L;
//================================================================
void insertHoaDon(HoaDon *&L, int pos)
{
    HoaDon *P = new HoaDon;
    cout << "Nhap ma khach hang: ";
    cin >> P->maKH;
    cout << "Nhap ho ten khach hang: ";
    cin.ignore();
    getline(cin, P->hoTenKH);
    cout << "Nhap dia chi khach hang: ";
    getline(cin, P->diaChi);
    cout << "Nhap so dien thoai khach hang: ";
    cin >> P->dienthoai;
    for (int i = 0; i < 4; i++)
    {
        cout << "Nhap tieu thu KW thang " << i + 1 << ": ";
        cin >> P->tieuthuKW[i];
        cout << "Nhap don gia dien: ";
        cin >> P->dongia[i];
    }
    P->next = NULL;

    if (pos == 0)
    {
        P->next = L;
        L = P;
        return;
    }
    HoaDon *prev = L;
    for (int i = 0; i < pos - 1; i++)
    {
        if (prev == NULL)
        {
            cout << "Vi tri chen khong hop le!" << endl;
            return;
        }
        prev = prev->next;
    }
    P->next = prev->next;
    prev->next = P;
}
//----------------------------------------------------------------
void print(HoaDon *&L)
{
    int tongtieuthuKW = 0;
    int thanhtoan = 0;
    cout << "Ma KH: ";
    cout << L->maKH << endl;
    cout << "Ho ten KH: ";
    cout << L->hoTenKH << endl;
    cout << "Dia Chi: ";
    cout << L->diaChi << endl;
    cout << "Dien Thoai: ";
    cout << L->dienthoai << endl;
    cout << "Tieu Thu\t"
         << "KW\t"
         << "Don Gia\t"
         << "Thanh tien";
    for (int i = 0; i < 4; i++)
    {
        L->thanhtien[i] = L->tieuthuKW[i] * L->dongia[i];
    }
    for (int i = 0; i < 4; i++)
    {
        tongtieuthuKW += L->tieuthuKW[i];
        L->tongtien += L->thanhtien[i];
    }
    L->gtgt = L->tongtien * 0.1;
    for (int i = 0; i < 4; i++)
    {
        thanhtoan = L->tongtien + L->gtgt;
    }
    cout << "\t" << tongtieuthuKW << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "\t" << L->tieuthuKW[i] << "\t" << L->dongia[i] << "\t" << L->thanhtien << endl;
    }

    cout << "Tong Tien"
         << "\t\t" << L->tongtien << endl;
    cout << "GTGT"
         << "\t\t" << L->gtgt << endl;
    cout << "Thanh toan"
         << "\t\t" << thanhtoan << endl;
}
//====================================================
int main()
{
    insertHoaDon(L, 1);
    print(L);
    system("pause");
    return 0;
}
