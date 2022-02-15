import numpy as np
import matplotlib as plt

nArray = [128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144]

class Edge:
    def __init__(self, weight, node1, node2):
        self.weight = weight
        self.n1 = node1
        self.n2 = node2

class Vertex: 
    def __init__(self, dim, pos = 0):
        self.pos = pos if pos else dim * [0]
        self.pos = pos

print("test")