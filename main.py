import numpy as np
import matplotlib as plt

class Edge:
    def __init__(self, weight, node1, node2):
        self.weight = weight
        self.n1 = node1
        self.n2 = node2

class Vertex: 
    def __init__(self, dim, pos = 0):
        self.pos = pos if pos else dim * [0]
        self.pos = pos
