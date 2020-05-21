#include <bits/stdc++.h>
using namespace std;
int r, c, n;
struct PLANT
{
    int x, y;
} plants[5001];
bool myCompare(const PLANT &ele1, const PLANT &ele2)
{
    if (ele1.x == ele2.x)
        return (ele1.y < ele2.y);
    return ele1.x < ele2.x;
}
bool inside(int x, int y)
{
    if (x <= r && x >= 1 && y <= c && y >= 1)
        return true;
    return false;
}
int searchPath(const PLANT secplant, int dx, int dy)
{
    PLANT plant;
    plant.x = secplant.x + dx;
    plant.y = secplant.y + dy;
    int steps = 2;
    while (inside(plant.x, plant.y))
    {
        if (!binary_search(plants, plants + n, plant, myCompare))
        {
            steps = 0;
            break;
        }
        plant.x += dx;
        plant.y += dy;
        steps++;
    }
    return steps;
}
int main()
{
    int i, j, dX, dY, pX, pY, steps, max = 2;
    scanf("%d%d", &r, &c);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &plants[i].x, &plants[i].y);
    sort(plants, plants + n, myCompare);
    for (i = 0; i < n - 2; i++)
        for (j = i + 1; j < n - 1; j++)
        {
            dX = plants[j].x - plants[i].x;
            dY = plants[j].y - plants[i].y;
            pX = plants[i].x - dX;
            pY = plants[i].y - dY;
            if (!inside(pX, pY))
                continue;
            if ((plants[i].x + max * dX) > r)
                break;
            pY = plants[i].y + max * dY;
            if (pY < 1 || pY > c)
                continue;
            steps = searchPath(plants[i], dX, dY);
            if (steps > max)
                max = steps;
        }
    if (max == 2)
        printf("0\n");
    else
        printf("%d\n", max);
    return 0;
}