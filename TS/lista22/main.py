from util import *
import numpy as np

n = 20

def main():
    graph = make_graph()
    matrix = make_matrix(n, 5)
    draw_graph(graph)
    print(matrix)

    #test_changing_N(0.8, 0.1, 128)
    #test_changing_capacity(0.8, 0.1, 128, 1.0625)
    #test_adding_edges(0.8, 0.1, 128)

if __name__ == "__main__":
    main()