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
                    # print(vertex, end=' ')
                    next_vertex.append(vertex)

        vertex_queue = next_vertex
        curr_level += 1
    return level, parent

def shortest_path(start, dest, graph):
    level, parent = bfs(start, graph)
    stack = []
    path = []
    while dest:
        stack.append(dest)
        dest = parent[dest]

    while stack:
        path.append(stack.pop())

    return path

print(shortest_path('c', 'f', graph))