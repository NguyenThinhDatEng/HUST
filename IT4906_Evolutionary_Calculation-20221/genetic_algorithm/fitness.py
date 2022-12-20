import numpy as np
import math


def fitness(gene):
    subGene = []
    for val in gene:
        subGene.append(val)
        if (val == -1):
            subGene = []
