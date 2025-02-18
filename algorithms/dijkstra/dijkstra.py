from heapq import heappush, heappop

def Dijkstra(graph, start, n):
    A = [None] * (n+1)
    queue = [(0, start)]
    while queue:
        path_len, v = heappop(queue)
        if A[v] is None:
            A[v] = path_len
            for w, edge_len in graph[v].items():
                if A[w] is None:
                    heappush(queue, (path_len + edge_len, w))
    return A

def l2i(l):
    r = 0
    for x in l: r += 1<<(x-1)
    return r

def check(r,f,g):
    if f == g: return True
    for x in r:
        if x | f == g: return True
    return False

def solve(n,m,k,ds,graph):
    r = set()
    g = 2 ** k - 1
    A = [None] * (n+1)
    queue = [(0, 1, ds[1])]
    while queue:
        path_len, v, f = heappop(queue)
        if A[v] is None:
            if v == n:
                if check(r,f,g): return path_len
                r.add(f)
            A[v] = {f:path_len}
            for w, edge_len in graph[v].items():
                nf = f | ds[w]
                if A[w] is None or nf not in A[w]:
                    heappush(queue, (path_len + edge_len, w, nf))
        elif f not in A[v]:
            if v == n:
                if check(r,f,g): return path_len
                r.add(f)
            A[v][f] = path_len
            for w, edge_len in graph[v].items():
                nf = f | ds[w]
                if A[w] is None or nf not in A[w]:
                    heappush(queue, (path_len + edge_len, w, nf))

n,m,k = map(int,raw_input().strip().split())
dsl = {}
ds = {}
for i in xrange(n):
    l = map(int,raw_input().strip().split())[1:]
    dsl[i+1] = set(l)
    ds[i+1] = l2i(l)

graph = {i:{} for i in xrange(1,n+1)}
for i in xrange(m):
    x,y,z = map(int,raw_input().strip().split())
    graph[x][y] = z
    graph[y][x] = z
print solve(n,m,k,ds,graph)

function shop(n: number, k: number, centers: string[], roads: number[][]): number {
    // Write your code here

}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const firstMultipleInput: string[] = readLine().replace(/\s+$/g, '').split(' ');

    const n: number = parseInt(firstMultipleInput[0], 10);

    const m: number = parseInt(firstMultipleInput[1], 10);

    const k: number = parseInt(firstMultipleInput[2], 10);

    let centers: string[] = [];

    for (let i: number = 0; i < n; i++) {
        const centersItem: string = readLine();
        centers.push(centersItem);
    }

    let roads: number[][] = Array(m);

    for (let i: number = 0; i < m; i++) {
        roads[i] = readLine().replace(/\s+$/g, '').split(' ').map(roadsTemp => parseInt(roadsTemp, 10));
    }

    const res: number = shop(n, k, centers, roads);

    ws.write(res + '\n');

    ws.end();

