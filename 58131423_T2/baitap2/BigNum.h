#ifndef BIGNUM_H
#define BIGNUM_H

class BigNum
{
	public:
		void Nhap();
		void Xuat();
		void Cong(BigNum, BigNum);
		void Tru(BigNum, BigNum);
		bool KiemTra(BigNum);
		void Nhan(BigNum, BigNum);
	protected:
		int n;
		int data[1000];
};

#endif
