"""
Task 3b: Greedy Algorithm - Gas Station Circuit
ST5003CEM Advanced Algorithms

There are n gas stations arranged in a circle. Station i has fuel[i] amount
of petrol and it costs cost[i] petrol to travel from station i to station
(i+1). Starting with an empty tank, find the starting station index that
allows completing the full circuit, or report that none exists.

Greedy choice: scan stations once, tracking a running "tank" balance
(fuel[i] - cost[i]). Whenever tank goes negative, no station in the range
[current_start .. i] can be a valid start (proof below), so greedily reset
start = i + 1 and tank = 0.

Run: python3 task3_greedy_gas_station.py
"""

import time
import random


def gas_station_greedy(fuel, cost):
    """O(n) time, O(1) space greedy solution.

    Correctness argument (optimality proof sketch):
    If total(fuel) < total(cost), no solution exists (pigeonhole - total
    deficit makes any full circuit impossible), so return -1 immediately.
    Otherwise a valid start is guaranteed to exist and is unique modulo
    which greedy identifies as follows: if starting at station `start` the
    running tank goes negative on reaching station i, then for any station
    j with start <= j <= i, starting at j cannot reach i+1 either -- because
    the tank arriving at j when starting from `start` was >= 0 (else we'd
    have failed earlier), so starting fresh at j (tank=0) can only do
    *worse* than continuing from `start` (tank>=0) up to that same point.
    Hence none of start..i can be the answer, and it is safe to jump the
    candidate start to i+1 without re-examining start..i.
    """
    n = len(fuel)
    total_tank, cur_tank = 0, 0
    start = 0
    for i in range(n):
        diff = fuel[i] - cost[i]
        total_tank += diff
        cur_tank += diff
        if cur_tank < 0:
            start = i + 1
            cur_tank = 0
    return start if total_tank >= 0 else -1


def gas_station_brute_force(fuel, cost):
    """O(n^2) exact check: try every starting station, simulate the full
    circuit. Used to verify the greedy result is optimal."""
    n = len(fuel)
    for start in range(n):
        tank = 0
        ok = True
        for step in range(n):
            i = (start + step) % n
            tank += fuel[i] - cost[i]
            if tank < 0:
                ok = False
                break
        if ok:
            return start
    return -1


def demo():
    # Classic example: answer should be station index 3
    fuel = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    g = gas_station_greedy(fuel, cost)
    bf = gas_station_brute_force(fuel, cost)
    print(f"fuel={fuel}\ncost={cost}")
    print(f"Greedy result: start station {g}")
    print(f"Brute-force result: start station {bf}")
    assert g == bf
    print("MATCH\n")

    # Infeasible example (total cost > total fuel)
    fuel2 = [2, 3, 4]
    cost2 = [3, 4, 5]
    g2 = gas_station_greedy(fuel2, cost2)
    bf2 = gas_station_brute_force(fuel2, cost2)
    print(f"Infeasible case -> greedy: {g2}, brute-force: {bf2} (expect -1, -1)")
    assert g2 == bf2 == -1
    print("MATCH\n")

    # Randomised correctness checks + timing comparison
    rnd = random.Random(11)
    mismatches = 0
    for trial in range(200):
        n = rnd.randint(1, 40)
        fuel_r = [rnd.randint(0, 20) for _ in range(n)]
        cost_r = [rnd.randint(0, 20) for _ in range(n)]
        gr = gas_station_greedy(fuel_r, cost_r)
        br = gas_station_brute_force(fuel_r, cost_r)
        # both -1, or both reach a feasible circuit (may differ in index
        # only if multiple valid starts exist and both are valid -- verify
        # feasibility rather than exact index equality)
        def feasible(start):
            if start == -1:
                return False
            tank = 0
            for step in range(n):
                i = (start + step) % n
                tank += fuel_r[i] - cost_r[i]
                if tank < 0:
                    return False
            return True

        ok = (gr == -1 and br == -1) or (feasible(gr) and feasible(br))
        if not ok:
            mismatches += 1
    print(f"Randomised trials: 200, mismatches: {mismatches} (expect 0)\n")

    print(f"{'n':>7} | {'greedy O(n) (ms)':>18} | {'brute O(n^2) (ms)':>18}")
    for n in [100, 1000, 5000, 10000]:
        fuel_r = [rnd.randint(0, 20) for _ in range(n)]
        cost_r = [rnd.randint(0, 20) for _ in range(n)]

        t = time.perf_counter()
        gas_station_greedy(fuel_r, cost_r)
        t_greedy = (time.perf_counter() - t) * 1000

        if n <= 5000:
            t = time.perf_counter()
            gas_station_brute_force(fuel_r, cost_r)
            t_brute = (time.perf_counter() - t) * 1000
            print(f"{n:>7} | {t_greedy:>18.4f} | {t_brute:>18.4f}")
        else:
            print(f"{n:>7} | {t_greedy:>18.4f} | {'skipped (too slow)':>18}")


if __name__ == "__main__":
    demo()
