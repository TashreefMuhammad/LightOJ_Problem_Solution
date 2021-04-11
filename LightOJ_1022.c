#include <stdio.h>
#include <math.h>

int main(void)
{
    int T, ts = 0;
    double r;

    scanf("%d", &T);

    while(++ts <= T)
    {
        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", ts, (2 - acos(0.0)) * 2 * r * r);
    }

    return 0;
}
