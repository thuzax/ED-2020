import sys

from matriz_adj import MatrizAdjacencia
from lista_adj import ListaAdjacencia

class Grafo:
    ''' Argumentos: 
                número de vértices 
                número de arestas
                tipo do grafo:
                    - Matriz de Adjacência: 'MA'
                    - Lista de Adjacência: 'LA'
    '''
    def __init__(self, num_vertices, arestas, tipo_grafo):
        self.num_vertices = num_vertices
        self.num_arestas = len(arestas)

        
        if (tipo_grafo == "LA"):
            self.grafo = ListaAdjacencia(num_vertices, arestas)
        elif (tipo_grafo == "MA"):
            self.grafo = MatrizAdjacencia(num_vertices, arestas)
    
    def get_num_vertices(self):
        return self.num_vertices

    def get_num_arestas(self):
        return self.num_arestas

    def get_grau_medio(self):
        return (2 * self.num_arestas / self.num_vertices)

    def get_espaco_alocado(self):
        tam_grafo = self.grafo.get_espaco_alocado()
        tam_grafo += sys.getsizeof(self.num_arestas)
        tam_grafo += sys.getsizeof(self.num_arestas)

        return tam_grafo

    def get_string(self):
        texto = self.grafo.get_string()
        return texto
