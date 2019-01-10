#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;
ofstream f("output1.txt", ifstream::out);
void Nhap (int a[100][100], int &n, int &m);
void Xuat (int a[100][100], int n, int m);
void Xoadong (int a[100][100], int &n, int m);
void Xoacot (int a[100][100], int n, int &m);
int Doixung (int a[100][100], int n, int m);
int SoHoangHau (int a[100][100], int n, int m, int vtd, int vtc);
void DSSoHoangHau (int a[100][100], int n, int m);

