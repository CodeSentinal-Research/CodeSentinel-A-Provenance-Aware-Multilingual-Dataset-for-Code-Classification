Here is the Python code for the problem:

def maxChildren(N, children_req, cookie_sizes):
    children_req.sort()
    cookie_sizes.sort()

    satisfied_children = 0

    children_itr = 0
    cookie_itr = 0

    while children_itr < N and cookie_itr < len(cookie_sizes):
        if children_req[children_itr] <= cookie_sizes[cookie_itr]:
            children_itr += 1
        cookie_itr += 1

    return children_itr

def main():
    N, M = map(int, input().split())

    children_req = list(map(int, input().split()))

    cookie_sizes = list(map(int, input().split()))

    print(maxChildren(N, children_req, cookie_sizes))

if __name__ == "__main__":
    main()

In this code, we first sort the children's requirements and the cookie sizes. Then, we initialize two iterators, one for the children and one for the cookies. We loop through all the requirements. If a child can get a cookie, we assign a cookie to them and move to the next child. If no child can get a cookie, we move to the next cookie. Finally, we return the number of satisfied children.