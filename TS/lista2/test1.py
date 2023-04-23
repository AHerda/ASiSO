import random
import networkx as nx
import matplotlib.pyplot as plt
from numpy import linspace, matrix
from copy import deepcopy
from main import make_graph, make_matrix, assign_capacity, assign_flow, delay_T, reliability

G = make_graph()
N = make_matrix()

assign_flow(G, N)
assign_capacity(G)

def increase_N(N, inc):
    for i in range(len(N)):
        for j in range(len(N[0])):
            N[i][j] += inc

def test1(T_max, p, m):
    out = []
    print('Testowanie niezawodnosci przy stopniowym zwiekszaniu wartosci w macierzy natezen')
    n = reliability(G, N, T_max, p, m)
    print('Niezawodnosc poczatkowa: {}'.format(n))
    for i in range(10):
        print('\trozpoczecie testu dla wartosci zwiekszonych o {}'.format((i+1)*5))
        increase_N(N,5) #zwiekszenie wartosci o 5
        r = reliability(G, N, T_max, p, m) #test
        out.append(r)
    i = 10
    with open('lista2/wyniki/natezenia.txt', 'w') as f:
        f.write('p = {}, T_max = {}, m = {}, niezawodnosc poczatkowa {}\n'.format(p, T_max, m, n))
        for r in out:
            f.write('Maksymalna liczba wysylanych pakietow: {} Niezawodnosc: {}\n'.format(i, r))
            i += 5

print(matrix(N))
test1(1, 0.8, 1)