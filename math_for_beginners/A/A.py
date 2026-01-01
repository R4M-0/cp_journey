import sys
from collections import defaultdict
 
sys.setrecursionlimit(2000)
input = sys.stdin.readline
 
def solve():
    try:
        line1 = input().split()
        if not line1: return
        N, S, L = map(int, line1)
        
        line2 = input().split()
        M, K, P = map(int, line2)
    except ValueError: return
 
    SP = S // P
    MP = M // P
    R = N * SP * K
    ports_per_group = SP * K
 
    oxc_connections = [[-1] * R for _ in range(M)]
    free_ports = [[set() for _ in range(N)] for _ in range(M)]
    
    for m in range(M):
        for g in range(N):
            base = g * ports_per_group
            for offset in range(ports_per_group):
                free_ports[m][g].add(base + offset)
 
    for _ in range(5):
        line = input()
        if not line: break
        Q = int(line.strip())
        
        flows = []
        demand_by_plane = [defaultdict(int) for _ in range(P)]
        flow_plane_assignments = [] 
 
        for i in range(Q):
            f = list(map(int, input().split()))
            flows.append(f + [i])
            assigned_plane = i % P
            flow_plane_assignments.append(assigned_plane)
            ga, gb = f[0], f[2]
            pair = (ga, gb) if ga < gb else (gb, ga)
            demand_by_plane[assigned_plane][pair] += 1
 
        for plane in range(P):
            oxc_start = plane * MP
            oxc_end = (plane + 1) * MP
            plane_links = defaultdict(list)
            
            for m in range(oxc_start, oxc_end):
                checked = set()
                for p_a in range(R):
                    if p_a in checked: continue
                    p_b = oxc_connections[m][p_a]
                    if p_b != -1:
                        checked.add(p_b)
                        g_a = p_a // ports_per_group
                        g_b = p_b // ports_per_group
                        if g_a < g_b:
                            pair = (g_a, g_b)
                            plane_links[pair].append((m, p_a, p_b))
                        else:
                            pair = (g_b, g_a)
                            plane_links[pair].append((m, p_b, p_a))
 
            for pair in list(plane_links.keys()):
                needed = demand_by_plane[plane][pair]
                links = plane_links[pair]
                if len(links) > needed:
                    to_remove = links[needed:]
                    plane_links[pair] = links[:needed]
                    for (m, p1, p2) in to_remove:
                        oxc_connections[m][p1] = -1
                        oxc_connections[m][p2] = -1
                        free_ports[m][p1 // ports_per_group].add(p1)
                        free_ports[m][p2 // ports_per_group].add(p2)
 
            pairs_needed = list(demand_by_plane[plane].keys())
            for pair in pairs_needed:
                needed = demand_by_plane[plane][pair]
                current = plane_links[pair]
                deficit = needed - len(current)
                if deficit > 0:
                    ga, gb = pair
                    for m in range(oxc_start, oxc_end):
                        if deficit <= 0: break
                        while deficit > 0 and free_ports[m][ga] and free_ports[m][gb]:
                            p_a = free_ports[m][ga].pop()
                            p_b = free_ports[m][gb].pop()
                            oxc_connections[m][p_a] = p_b
                            oxc_connections[m][p_b] = p_a
                            current.append((m, p_a, p_b))
                            deficit -= 1
 
        output_routes = [None] * Q
        grouped_flows = [defaultdict(list) for _ in range(P)]
        for f in flows:
            idx = f[4]
            plane = flow_plane_assignments[idx]
            ga, gb = f[0], f[2]
            pair = (ga, gb) if ga < gb else (gb, ga)
            grouped_flows[plane][pair].append(f)
 
        for plane in range(P):
            oxc_start = plane * MP
            oxc_end = (plane + 1) * MP
            final_links = defaultdict(list)
            for m in range(oxc_start, oxc_end):
                checked = set()
                for p_a in range(R):
                    if p_a in checked: continue
                    p_b = oxc_connections[m][p_a]
                    if p_b != -1:
                        checked.add(p_b)
                        g_a = p_a // ports_per_group
                        g_b = p_b // ports_per_group
                        pair = (g_a, g_b) if g_a < g_b else (g_b, g_a)
                        final_links[pair].append((m, p_a, p_b))
 
            for pair, flow_list in grouped_flows[plane].items():
                links = final_links[pair]
                if not links:
                    for f in flow_list:
                         output_routes[f[4]] = (0, 0, 0, 0, 0)
                    continue
                for i, f in enumerate(flow_list):
                    link = links[i % len(links)]
                    m, p_a, p_b = link
                    if (p_a // ports_per_group) == f[0]:
                        src_port, dst_port = p_a, p_b
                    else:
                        src_port, dst_port = p_b, p_a
                    rel_src = src_port % ports_per_group
                    s_src = plane * SP + (rel_src // K)
                    l_src = rel_src % K
                    rel_dst = dst_port % ports_per_group
                    s_dst = plane * SP + (rel_dst // K)
                    l_dst = rel_dst % K
                    output_routes[f[4]] = (s_src, l_src, m, s_dst, l_dst)
 
        for m in range(M):
            print(*(oxc_connections[m]))
        for r in output_routes:
            print(f"{r[0]} {r[1]} {r[2]} {r[3]} {r[4]}")
        sys.stdout.flush()
 
if __name__ == "__main__":
    solve()
