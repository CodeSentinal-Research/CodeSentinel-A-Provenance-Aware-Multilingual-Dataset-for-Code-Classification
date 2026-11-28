def asteroidCollision(asteroids):
    stack = []
    for asteroid in asteroids:
        while stack and asteroid < 0 and 0 < stack[-1]:
            if stack[-1] < -asteroid:
                stack.pop()
            elif stack[-1] == -asteroid:
                stack.pop()
            break
        else:
            stack.append(asteroid)
    return stack

asteroids = [5, 10, -5]
print(asteroidCollision(asteroids))  

asteroids = [5, 10, 1000, -5]
print(asteroidCollision(asteroids))  

asteroids = [-10, 8, -5, -5]
print(asteroidCollision(asteroids))  

asteroids = [10, 20, -10, 1000, 30]
print(asteroidCollision(asteroids))