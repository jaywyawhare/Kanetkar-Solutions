/* In digital world colors are specified in Red-Green-Blue (RGB) format, with values of R, G, B varying on an integer scale from 0 to 255. In print publishing the colors are mentioned in Cyan-Magenta-Yellow-Black (CMYK) format, with values of C, M, Y, K varying on a real scale from 0.0 to 1.0. Write a program that helps a user to convert RGB color values to CMYK color as per the following formulas:
    
    - White = max(Red/255, Green/255, Blue/255)
    - Cyan = (White - Red/255) / White
    - Magenta = (White - Green/255) / White
    - Yellow = (White - Blue/255) / White
    - Black = 1 - White

    Note that if the RGB values are all 0, then the CMY values are all 0 and K is 1.0. 
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

struct test
{
    int r;
    int g;
    int b;
    double c;
    double m;
    double y;
    double k;
};

void rgbToCmyk(int r, int g, int b, double *c, double *m, double *y, double *k)
{
    if (r == 0 && g == 0 && b == 0) {
        *c = *m = *y = 0;
        *k = 1.0;
        return;
    }

    double red = r / 255.0;
    double green = g / 255.0;
    double blue = b / 255.0;

    double white = fmax(red, fmax(green, blue));
    *c = (white - red) / white;
    *m = (white - green) / white;
    *y = (white - blue) / white;
    *k = 1 - white;
}

bool testFunction(int r, int g, int b, double c, double m, double y, double k)
{
    double cmyk[4];
    rgbToCmyk(r, g, b, &cmyk[0], &cmyk[1], &cmyk[2], &cmyk[3]);
    return cmyk[0] == c && cmyk[1] == m && cmyk[2] == y && cmyk[3] == k;
}

void runTests()
{
    struct test tests[] = {
        {0, 0, 0, 0, 0, 0, 1},
        {255, 255, 255, 0, 0, 0, 0},
        {255, 0, 0, 0, 1, 1, 0},
        {0, 255, 0, 1, 0, 1, 0},
        {0, 0, 255, 1, 1, 0, 0},
        {255, 255, 0, 0, 0, 1, 0},
        {255, 0, 255, 0, 1, 0, 0},
        {0, 255, 255, 1, 0, 0, 0},
    };

    bool allTestsPassed = true;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!testFunction(tests[i].r, tests[i].g, tests[i].b, tests[i].c, tests[i].m, tests[i].y, tests[i].k))
        {
            printf("Test failed: R = %d, G = %d, B = %d, Expected = C: %f, M: %f, Y: %f, K: %f\n", tests[i].r, tests[i].g, tests[i].b, tests[i].c, tests[i].m, tests[i].y, tests[i].k);
            double c, m, y, k;
            rgbToCmyk(tests[i].r, tests[i].g, tests[i].b, &c, &m, &y, &k);
            printf("Got: C: %f, M: %f, Y: %f, K: %f\n", c, m, y, k);
            allTestsPassed = false;
        }
    }

    if (allTestsPassed)
    {
        printf("All tests passed\n");
    }
}

void printCmyk()
{
    int r, g, b;
    printf("Enter the RGB values: ");
    scanf("%d %d %d", &r, &g, &b);
    double c, m, y, k;
    rgbToCmyk(r, g, b, &c, &m, &y, &k);
    printf("The CMYK values are: C: %f, M: %f, Y: %f, K: %f\n", c, m, y, k);
}

int main()
{
    runTests();
    printCmyk();
    return 0;
}
