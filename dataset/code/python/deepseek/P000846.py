def minimizedMaximumOfProductsDistributedToAnyStore(n, m, quantities):
    quantities.sort()

    max_quantity = quantities[-1]

    min_quantity = quantities[0]

    range_quantities = max_quantity - min_quantity

    max_products = max(0, (max_quantity - 1) - (n - m))

    return max_products


def handle_input():
    n = int(input("Enter the number of stores: "))
    m = int(input("Enter the number of products: "))
    quantities = list(map(int, input("Enter the quantities of the products: ").split()))
    return n, m, quantities


def main():
    n, m, quantities = handle_input()
    result = minimizedMaximumOfProductsDistributedToAnyStore(n, m, quantities)
    print("The minimum possible maximum number of products assigned to any store is: ", result)


if __name__ == "__main__":
    main()