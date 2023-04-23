import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import random
from copy import deepcopy

# Zmienne
v = 20
edges = []

def main():
    G = make_graph()
    N = make_matrix()
    print(np.matrix(N))

    assign_flow(G, N)
    assign_capacity(G)

    draw_graph(G)

def make_graph(v = 20):
    G = nx.Graph()
    G.add_nodes_from(list(range(v)))
    
    edges_temp = []
    for i in range(v - 1):
        edges_temp.append((i, i + 1))
    edges_temp.extend(((0, 4), (14, 5), (15, 19)))
    edges_temp.remove((4, 5))
    edges_temp.remove((14, 15))

    i = 0
    j = 5
    while i<5:
        edges_temp.append((i,j))
        edges_temp.append((i+15, j+1))
        i += 1
        j += 2
    for i, j in edges_temp:
        G.add_edge(i, j)
    
    edges = edges_temp
    
    return G

def draw_graph(graph):
    plt.figure(figsize=(8, 8))
    pos = nx.shell_layout(graph, (list(range(5)), list(range(5, 15)), list(range(15, 20))), .4)
    #pos = nx.spring_layout(graph)
    nx.draw_networkx_edge_labels(graph, pos, font_size=6, bbox=dict(fc = "w", linewidth = 0, alpha=1.0))
    nx.draw_networkx_labels(graph, pos, font_color="w")
    nx.draw(graph, pos)
    plt.savefig("lista2/wykresy/Graf.png", dpi=400)

def make_matrix(v = 20):
    matrix = []
    for i in range(v):
        matrix.append([])
        for j in range(v):
            if i == j:
                matrix[i].append(0)
            else:
                matrix[i].append(random.randint(1, 9))
    return matrix


def generate_path(graph, i, j, package):
    try:
        path = nx.dijkstra_path(graph, i, j)
    except:
        return []
    if_ok = False
    gen = nx.all_simple_paths(graph, source = i, target = j)
    while not if_ok:
        if_ok = True
        for k in range(0, len(path)-1):
            if graph[path[k]][path[k+1]]["a"] + package > graph[path[k]][path[k+1]]["c"]:
                if_ok = False 
                try:
                    path = next(gen)
                except:
                    path = []
                break
    return path

def assign_flow(graph, matrix):
    nx.set_edge_attributes(graph, 0, "a")
    nodes = nx.number_of_nodes(graph)
    for i in range(nodes):
        for j in range(nodes):
            path = nx.shortest_path(graph, i, j)
            if len(path) == 0:
                return False
            for n in range(len(path) - 1):
                graph[path[n]][path[n + 1]]["a"] += matrix[i][j]
    return True


def assign_capacity(graph):
    nx.set_edge_attributes(graph, 0, "c")
    for i, j in graph.edges:
        graph[i][j]["c"] = graph[i][j]["a"] // 5 * 50 + 50

def delay_T(graph, matrix, m):
    delay = 0
    G = sum(sum(row) for row in matrix)
    for i, j in graph.edges:
        a = graph[i][j]["a"]
        c = graph[i][j]["c"]
        temp = a / (c / m - a)
        if temp < 0:
            return -1
        else:
            delay += temp
    print(delay / G)
    return delay / G


def reliability(graph, matrix, T_max, p, m):
    counter = 0
    for _ in range(1000):
        graph_temp = graph.copy()
        to_del = []
        for edge in graph.edges:
            i = random.uniform(0.0,1.0)
            if i > p:
                to_del.append(edge)
        for edge in to_del:
            graph_temp.remove_edge(*edge)
        connected_flag = assign_flow(graph_temp, matrix)
        if connected_flag:
            T = delay_T(graph_temp, matrix, m)
            if T < T_max and T > 0: 
                counter += 1
    return counter/1000


if __name__ == "__main__":
    main()