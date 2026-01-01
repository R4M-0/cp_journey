#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct Flow {
    int id;
    int gA, leafA, gB, leafB;
};

struct RouteResult {
    int sA, kA, m, sB, kB;
};

int N, S, L;
int M, K, P;
int R; 

inline int get_port_id(int group, int spine, int link) {
    int spines_per_plane = S / P;
    int spine_in_plane = spine % spines_per_plane; 
    return group * spines_per_plane * K + spine_in_plane * K + link;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> S >> L >> M >> K >> P)) return 0;

    R = N * (S / P) * K; 

    vector<vector<int>> current_oxc_topo(M, vector<int>(R, -1));

    for (int q_idx = 0; q_idx < 5; ++q_idx) {
        int Q;
        if (!(cin >> Q)) break;

        vector<Flow> flows(Q);
        for (int i = 0; i < Q; ++i) {
            flows[i].id = i;
            cin >> flows[i].gA >> flows[i].leafA >> flows[i].gB >> flows[i].leafB;
        }

        vector<RouteResult> results(Q);
        vector<vector<bool>> port_used(M, vector<bool>(R, false));
        vector<bool> flow_routed(Q, false);

        for (int i = 0; i < Q; ++i) {
            const auto& f = flows[i];
            bool found = false;

            for (int m = 0; m < M && !found; ++m) {
                int plane = m / (M / P);
                int s_start = plane * (S / P);
                int s_end = (plane + 1) * (S / P);

                for (int sA = s_start; sA < s_end && !found; ++sA) {
                    for (int sB = s_start; sB < s_end && !found; ++sB) {
                        for (int kA = 0; kA < K && !found; ++kA) {
                            for (int kB = 0; kB < K && !found; ++kB) {
                                int pA = get_port_id(f.gA, sA, kA);
                                int pB = get_port_id(f.gB, sB, kB);

                                if (current_oxc_topo[m][pA] == pB && !port_used[m][pA] && !port_used[m][pB]) {
                                    port_used[m][pA] = true;
                                    port_used[m][pB] = true;
                                    results[i] = {sA, kA, m, sB, kB};
                                    flow_routed[i] = true;
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < Q; ++i) {
            if (flow_routed[i]) continue;
            
            const auto& f = flows[i];
            bool found = false;
            
            for (int m = M - 1; m >= 0 && !found; --m) {
                
                int plane = m / (M / P); 
                int s_start = plane * (S / P);
                int s_end = (plane + 1) * (S / P);

                for (int sA = s_start; sA < s_end && !found; ++sA) {
                    for (int sB = s_start; sB < s_end && !found; ++sB) {
                        for (int kA = 0; kA < K && !found; ++kA) {
                            for (int kB = 0; kB < K && !found; ++kB) {
                                
                                int pA = get_port_id(f.gA, sA, kA);
                                int pB = get_port_id(f.gB, sB, kB);

                                if (!port_used[m][pA] && !port_used[m][pB]) {
                                    int old_A = current_oxc_topo[m][pA];
                                    if (old_A != -1) current_oxc_topo[m][old_A] = -1;
                                    
                                    int old_B = current_oxc_topo[m][pB];
                                    if (old_B != -1) current_oxc_topo[m][old_B] = -1;

                                    current_oxc_topo[m][pA] = pB;
                                    current_oxc_topo[m][pB] = pA;

                                    port_used[m][pA] = true;
                                    port_used[m][pB] = true;

                                    results[i] = {sA, kA, m, sB, kB};
                                    flow_routed[i] = true;
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int m = 0; m < M; ++m) {
            for (int r = 0; r < R; ++r) {
                cout << current_oxc_topo[m][r] << (r == R - 1 ? "" : " ");
            }
            cout << "\n";
        }

        for (int i = 0; i < Q; ++i) {
            cout << results[i].sA << " " 
                 << results[i].kA << " " 
                 << results[i].m << " " 
                 << results[i].sB << " " 
                 << results[i].kB << "\n";
        }
    }

    return 0;
}
