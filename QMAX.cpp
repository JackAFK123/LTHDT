#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CayPhanDoan {
public:
    int soPhanTu; 
    vector<int> giaTriCay, P; 

    CayPhanDoan(int n) : soPhanTu(n), giaTriCay(4 * n, 0), P(4 * n, 0) {}

    void capNhat(int u, int v, int k) {
        capNhat(1, 0, soPhanTu - 1, u, v, k);
    }

    int truyVan(int u, int v) {
        return truyVan(1, 0, soPhanTu - 1, u, v);
    }

private:
    void day(int nut, int batDau, int ketThuc) {
        if (P[nut] != 0) {
            giaTriCay[nut] += P[nut];
            if (batDau != ketThuc) {
                P[2 * nut] += P[nut];
                P[2 * nut + 1] += P[nut];
            }
            P[nut] = 0;
        }
    }

    void capNhat(int nut, int batDau, int ketThuc, int u, int v, int k) {
        day(nut, batDau, ketThuc);
        if (batDau > ketThuc || batDau > v || ketThuc < u)
            return;

        if (batDau >= u && ketThuc <= v) {
            giaTriCay[nut] += k;
            if (batDau != ketThuc) {
                P[2 * nut] += k;
                P[2 * nut + 1] += k;
            }
            return;
        }

        int giua = (batDau + ketThuc) / 2;
        capNhat(2 * nut, batDau, giua, u, v, k);
        capNhat(2 * nut + 1, giua + 1, ketThuc, u, v, k);
        giaTriCay[nut] = max(giaTriCay[2 * nut], giaTriCay[2 * nut + 1]);
    }

    int truyVan(int nut, int batDau, int ketThuc, int u, int v) {
        day(nut, batDau, ketThuc);
        if (batDau > ketThuc || batDau > v || ketThuc < u)
            return 0;

        if (batDau >= u && ketThuc <= v)
            return giaTriCay[nut];

        int giua = (batDau + ketThuc) / 2;
        return max(truyVan(2 * nut, batDau, giua, u, v), truyVan(2 * nut + 1, giua + 1, ketThuc, u, v));
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    CayPhanDoan cayPhanDoan(n);

    for (int i = 0; i < m; ++i) {
        int u, v, k;
        cin >> u >> v >> k;
        cayPhanDoan.capNhat(u - 1, v - 1, k);
    }

    int p;
    cin >> p;

    for (int i = 0; i < p; ++i) {
        int u, v;
        cin >> u >> v;
        cout << cayPhanDoan.truyVan(u - 1, v - 1) << endl;
    }

    return 0;
}

