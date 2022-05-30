#include <math.h>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#define CLEAR "\x1b[2J"
void rotate_donut_3D()
{

  int k;
  system("cls");
  float A = 0, B = 0, i, j, z[1760];
  char b[1760];
  printf(CLEAR); //<= xoa man hinh va dua con tro vao vi tri cuoi cung (da viet tren man hinh console)
  for (;;)
  {
    memset(b, 32, 1760);// 32 trong ma ascii la ' ';
    memset(z, 0, 7040);// 0 trong ma ascii la "Khong nho len mang search";
    
    //=====Nap gia tri cho "p"=====
    for (j = 0; 6.28 > j; j += 0.07)
      for (i = 0; 6.28 > i; i += 0.02)
      {
        float c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A),
              h = d + 2, D = 1 / (c * h * e + f * g + 5), l = cos(i),
              m = cos(B), n = sin(B), t = c * h * g - f * e;
        int x = 40 + 30 * D * (l * h * m - t * n),
            y = 12 + 15 * D * (l * h * n + t * m), o = x + 80 * y,
            N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
        if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o])
        {
          z[o] = D;
          b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
        }
      }
    printf("\x1b[H"); // dua con tro ve vi tri dau cua console roi khi ket thuc cau lenh thi xoa man hinh xoa man hinh
    // system("cls");// khong dung systeam("cls") vi no khien console bi giat mat tham mi
    for (k = 0; k < 1761; k++)
      putchar(k % 80 ? b[k] : 10); // => in cai banh donut =))
    A += 0.04;
    B += 0.02;
  }
}

int _tmain(int argc, _TCHAR *argv[])
{
  rotate_donut_3D();
  return 0;
}
