import networkx as nx
import matplotlib.pyplot as plt
from random import randint, uniform
import numpy as np

edg = []


#funckja generujaca dodecahedron
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
    
    global edg
    edg = edges_temp
    
    return G

#funkcja tworzy wizualizacje grafu
def draw_graph(graph):
    plt.figure(figsize=(8, 8))
    pos = nx.shell_layout(graph, (list(range(5)), list(range(5, 15)), list(range(15, 20))), .4)
    #pos = nx.spring_layout(graph)
    nx.draw_networkx_edge_labels(graph, pos, font_size=6, bbox=dict(fc = "w", linewidth = 0, alpha=1.0))
    nx.draw_networkx_labels(graph, pos, font_color="w")
    nx.draw(graph, pos)
    plt.savefig("lista22/wykresy/Graf.png", dpi=400)

#funkcja generujaca macierz natezen o maksymalnej liczbie wysylanych pakietow max
def make_matrix(v, max):
    matrix = np.zeros((v, v), dtype=int)
    for i in range(v):
        for j in range(v):
            if i == j:
                matrix[i][j] = 0
            else:
                matrix[i][j] = randint(0, max)
    return matrix

#funkcja generujaca przeplyw, wraca true jezeli z kazdego wierzcholka mozna wszedzie wyslac okreslona w macierzy natezen liczbe pakietow
def generate_flow(graph, N):
    for i in range(len(N)):
        for j in range(len(N)):
            if N[i][j] != 0:
                path = generate_path(graph, i, j, N[i][j]) #generowanie sciezki z wierzcholka i do j
                if len(path) == 0:
                    return False #jezeli nie udalo sie przeslac pakietow to wracamy false
                for k in range(0, len(path)-1):
                    graph[path[k]][path[k+1]]['taken'] += N[i][j] #zwiekszenie przeplywu na kazdej krawedzi na trasie o liczbe przesylanych pakietow
    return True

#funkcja generujaca przepustowosc sieci
def generate_capacity(graph, N, m):
    for i in range(len(N)):
        max_size = max(N[i])
        for edge in graph.edges(i, data = True):
            edge[2]['capacity'] = max_size * len(N)**2 * m * uniform(2.0, 3.0)

#funkcja generujaca sciezke package pakietow z wierzcholka i do j
def generate_path(graph, i, j, package):
    try:
        path = nx.dijkstra_path(graph,i,j) #najpierw znajdujemy najkrotsza sciezke algorytmem dijksty
    except:
        return [] #jezeli nie istnieje to znaczy, ze graf sie rozspojnil
    if_ok = False
    gen = nx.all_simple_paths(graph, source = i, target = j) #generator wracajacy wszystkie sciezki z i do j
    while not if_ok:
        if_ok = True
        for k in range(0, len(path)-1):
            if graph[path[k]][path[k+1]]['taken'] + package > graph[path[k]][path[k+1]]['capacity']: #sprawdzamy czy pakiety 'zmieszcza sie' na wybranej trasie
                if_ok = False 
                try:
                    path = next(gen) #jezeli sie nie mieszcza to bierzemy kolejna trase
                except:
                    path = [] #jezeli wyczerpalismy wszystkie sciezki to znaczy, ze nie mozna przeslac pakietow z i do j
                break
    return path

#funkcja liczaca opoznienie pakietow wedlug wzoru z polecenia
def calculate_delay(graph, N, m):
    G = 0
    for row in N:
        for num in row:
            G += num
    sum_e = 0
    for i in range(len(N)):
        for edge in graph.edges(i, data = True):
            term = edge[2]['taken']/(edge[2]['capacity']/m-edge[2]['taken']) #liczenie wyrazenia dla kazdej krawedzi
            if term < 0: #jezeli wyszlo ujemne to znaczy, ze krawedz zostala przeciazona i nalezy wrocic fail
                return -1
            else:
                sum_e += term
    return 1/G * sum_e

#funkcja liczace miare niezawodnosci sieci
def calculate_reliability(graph, N, p, T_max, m):
    counter = 0
    for _ in range(1000):
        helper = graph.copy() #tworzenie kopii grafu wejsciowego, na ktorej bedzie prowadzona proba
        to_del = []
        for edge in graph.edges:
            i = uniform(0.0,1.0) #dla kazdej krawedzi losujemy czy zostatnie usunieta
            if i > p:
                to_del.append(edge)
        for edge in to_del:
            helper.remove_edge(*edge) #usuwamy wybrane krawedzi
        if_connected = generate_flow(helper, N) #generujemy na nowo przeplyw
        if if_connected: #jezeli nie doszlo do rozspojnienia to przeprowadzamy test
            T = calculate_delay(helper, N, m)
            if T < T_max and T > 0: 
                counter += 1
    return counter/1000