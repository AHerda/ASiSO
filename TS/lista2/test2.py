from util import *

#funkcja zwiekszajaca przepustowosci krawedzi
def increase_capacity(graph, mul):
    for i in range(20):
        for edge in graph.edges(i, data = True):
            edge[2]["c"] *= mul

def test2(p, T_max, m, mul, plot = False):
    graph = make_graph()
    matrix = make_matrix(20, 50)
    generate_capacity(graph, matrix, m//16)
    generate_flow(graph, matrix)

    out = np.zeros(11)
    dane = np.zeros(11)

    out[0] = (calculate_reliability(graph, matrix, p, T_max, m))
    dane[0] = 1

    for i in range(10):
        increase_capacity(graph, mul)
        out[i + 1] = calculate_reliability(graph, matrix, p, T_max, m)
        dane[i + 1] = dane[i] * mul
    
    if plot:
        draw_plot(dane, out)

    return out

def draw_plot(dane, wyniki):
    plt.figure()

    plt.title("Wykres niezawodności od przepustowości")
    plt.xlabel("Przepustowość zwiękoszona x razy")
    plt.ylabel("Niezawodność")

    plt.plot(dane, wyniki, "b-o")

    plt.savefig("wykresy/test2.png", dpi=300)
    plt.close()