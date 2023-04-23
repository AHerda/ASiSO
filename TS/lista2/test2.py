import networkx as nx
import matplotlib.pyplot as plt
from numpy import linspace
from copy import deepcopy
from main import make_graph, make_matrix, assign_capacity, assign_flow, delay_T, reliability

G = make_graph()
N = make_matrix()

assign_flow(G, N)
assign_capacity(G)


def test2(graph, matrix, T_max, p, m, iterations=10):
    test_graph = deepcopy(graph)
    results = [reliability(test_graph, matrix, T_max, p, m)]
    for _ in range(iterations):
        for i, j in test_graph.edges:
            test_graph[i][j]["c"] += 50
        results.append(reliability(test_graph, matrix, T_max, p, m))
    return results


min_Tmax = [delay_T(G, N, m) for m in range(1, 11)]

for m in range(10, 0, -2):
    startT = min_Tmax[m - 1]
    for p in linspace(0.9, 0.99, num=5):
        plt.figure()
        plt.imshow(
            [test2(G, N, Tmax, p, m) for Tmax in linspace(startT, 10 * startT, num=10)],
            extent=[0, 10, startT, 10 * startT],
            aspect="auto",
            origin="lower",
        )
        plt.colorbar()
        plt.ylabel("T_max")
        plt.xlabel("Wzrost przepustowości każdego łącza w Mb/s p={}, m={}".format(p, m))
        plt.savefig("TEST2_{}_{}.png".format(m, p))
        plt.close()