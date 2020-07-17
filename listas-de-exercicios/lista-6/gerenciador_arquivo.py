def ler_grafo(nome_arquvio):
    with open(nome_arquvio, "r") as arquivo:
        texto = arquivo.read().splitlines()

    num_vertices = int(texto[0])
    arestas = []

    for i in range(1, len(texto)):
        aresta_txt = texto[i].split()
        aresta = (int(aresta_txt[0]), int(aresta_txt[1]))
        arestas.append(aresta)
    
    return (num_vertices, arestas)
