def is_possible(A, B):
    if B[::-1] == A:
        return True
    else:
        return False

def main():
    A = input().strip()
    B = input().strip()
    
    if is_possible(A, B):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()