def reconstruct_bst(postorder):
    if not postorder:
        return None

    root = postorder.pop()

    left_subtree = [node for node in postorder if node < root]
    right_subtree = [node for node in postorder if node > root]

    root.left = reconstruct_bst(left_subtree)
    root.right = reconstruct_bst(right_subtree)

    return root


def main():
    N = int(input().strip())

    postorder = list(map(int, input().strip().split()))

    bst = reconstruct_bst(postorder)
    print(bst)


if __name__ == "__main__":
    main()