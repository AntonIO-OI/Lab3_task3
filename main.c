#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, p, q, d;
    char er, ch;

    do {
        er = ch = 0;

        printf("Enter a:\n");
        scanf("%f%c", &a, &ch);

        if (ch != '\n')
        {
            er = 1;
            fflush(stdin);
            printf("Error input (a)\n");
        }
    } while (er);

    do {
        er = ch = 0;

        printf("Enter b:\n");
        scanf("%f%c", &b, &ch);

        if (ch != '\n')
        {
            er = 1;
            fflush(stdin);
            printf("Error input (b)\n");
        }
    } while (er);

    do {
        er = ch = 0;

        printf("Enter c:\n");
        scanf("%f%c", &c, &ch);

        if (ch != '\n')
        {
            er = 1;
            fflush(stdin);
            printf("Error input (c)\n");
        }
    } while (er);

    p = b - powf(a, 2) / 3;
    q = (2 * powf(a, 3) / 27) - (a * b / 3) + c;

    d = (powf(p, 3) / 27 + powf(q, 2) / 4);

    if (d > 0)
    {
        float y, x1, u, v;
        y = -(q / 2) + sqrtf(d);

        u = (y > 0) ? (powf(y, (float)1/3)) : (powf(fabsf(y), (float)1/3)*-1);
        v = -(p / (3 * u));

        x1 = u + v - a / 3;

        printf("x1 = %f\n", x1);
        printf("x2 = %f + %fi\n", (-((u+v)/2) - a / 3), (powf(3, (float)1/2)*(u-v)/2));
        printf("x3 = %f - %fi\n", (-((u+v)/2) - a / 3), (powf(3, (float)1/2)*(u-v)/2));
    } else if (d == 0)
    {
        float x1, x2;

        x1 = (-(3 * q / 2 * p) - a / 3);

        printf("x1 = %f\n", x1);

        if (p != 0)
        {
            x2 = (3 * q) / p - a / 3;

            printf("x2 = x3 = %f\n", x2);
        }
    } else
    {
        if (-(pow(p, 3) / 27) >= 0)
        {
            float r, fi, x1, x2, x3;

            r = sqrtf(-(powf(p, 3) / 27));
            fi = acosf(-(q / (2 * r)));

            x1 = 2 * fabsf(powf(r, (float)1/3)) * cosf(fi/3) - a / 3;
            x2 = 2 * fabsf(powf(r, (float)1/3)) * cosf((fi + 2 * (float)M_PI) / 3) - a / 3;
            x3 = 2 * fabsf(powf(r, (float)1/3)) * cosf((fi + 4 * (float)M_PI) / 3) - a / 3;

            printf("x1 = %f\nx2 = %f\nx3 = %f\n", x1, x2, x3);

        } else
        {
            printf("INCORRECT VALUE\n");
        }
    }

    return 0;
}
