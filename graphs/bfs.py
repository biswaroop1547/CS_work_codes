graph = {
    'a' : ['b', 'c', 'e'],
    'c' : ['a', 'e'],
    'e' : ['a', 'c', 'd'],
    'b' : ['a', 'd', 'f'],
    'd' : ['b', 'e', 'f'],
    'f' : ['b', 'd']
}

def bfs(s, graph):
    level = {s : 0}
    parent = {s : None}

    vertex_queue = [s]
    curr_level = 1
    while vertex_queue:
        next_vertex = []
        for u in vertex_queue:
            for vertex in graph[u]:
                if vertex not in level:
                    level[vertex] = curr_level
                    parent[vertex] = u
                    print(vertex, end=' ')
                    next_vertex.append(vertex)

        vertex_queue = next_vertex
        curr_level += 1
    return level, parent

level, parent = bfs('c', graph)

print("\nlevel : ", level)
print("parent : ", parent)