# graph = {
#     'a' : ['b', 'c', 'e'],
#     'c' : ['a', 'e'],
#     'e' : ['a', 'c', 'd'],
#     'b' : ['a', 'd', 'f'],
#     'd' : ['b', 'e', 'f'],
#     'f' : ['b', 'd'],
#     'h' : ['i', 'j'],
#     'i' : ['h', 'j'],
#     'j' : ['h', 'i'],
# }

graph = {
    'g' : ['h'],
    'a' : ['h', 'b'],
    'h' : [],
    'd' : ['b', 'e'],
    'e' : ['f'],
    'b' : ['c'],
    'c' : ['f'],
    'f' : [],
    'i' : []
}

def dfs_visit(s, graph, parent = None):
    if parent is None:
        parent = {s : None}
    finish_list = []
    def dfs_visit_recurr(s, graph):
        for v in graph[s]:
            if v not in parent:
                parent[v] = s
                dfs_visit_recurr(v, graph)
                finish_list.append(v)
        return (parent, finish_list)

    return dfs_visit_recurr(s, graph)


def dfs(vertex_list, graph):
    parent = {}
    paths = []
    for v in vertex_list:
        if v not in parent:
            parent[v] = None
            parent, path = dfs_visit(v, graph, parent)
            path.append(v)
            paths.extend(path)
            
    return paths, parent


print(dfs(graph.keys(), graph)[0][: : -1])
# print(dfs_visit('d', graph))