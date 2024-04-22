#include <stdio.h>

#define MAXVAL 10

int main(void)
{
    for (int a = 1; a < MAXVAL; ++a) {
        for (int b = 1; b < MAXVAL; ++b) {
            for (int c = 1; c < MAXVAL; ++c) {
                for (int d = 1; d < MAXVAL; ++d) {
                    for (int e = 1; e < MAXVAL; ++e) {
                        for (int f = 1; f < MAXVAL; ++f) {
                            for (int g = 1; g < MAXVAL; ++g) {
                                for (int h = 1; h < MAXVAL; ++h) {
                                    for (int i = 1; i < MAXVAL; ++i) {
                                        if (a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i
                                                && b != c && b != d && b != e && b != f && b != g && b != h && b != i
                                                && c != d && c != e && c != f && c != g && c != h && c != i
                                                && d != e && d != f && d != g && d != h && d != i
                                                && e != f && e != g && e != h && e != i
                                                && f != g && f != h && f != i
                                                && g != h && g != i
                                                && h != i
                                           ) printf("%d%d%d%d%d%d%d%d%d\n", a, b, c, d, e, f, g, h, i);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
