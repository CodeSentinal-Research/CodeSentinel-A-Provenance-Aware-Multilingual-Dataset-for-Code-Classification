import random
import math
import time
from typing import List, Tuple

class PrimeGenerator:
    """
    A class for generating cryptographic keys using prime numbers.
    This implements a simplified version of key generation algorithms
    used in RSA-type cryptosystems.
    """
    
    def __init__(self, min_range: int = 100, max_range: int = 1000):
        """
        Initialize the key generator with a range for prime selection.
        
        Arguments:
            min_range: Minimum value for prime number range
            max_range: Maximum value for prime number range
        """
        self.min_range = min_range
        self.max_range = max_range
        self.primes_cache = self._sieve_of_eratosthenes(max_range)
    
    def _sieve_of_eratosthenes(self, limit: int) -> List[int]:
        """
        Generate all prime numbers up to limit using Sieve of Eratosthenes.
        This is an efficient algorithm for finding all primes up to a given limit.
        
        Args:
            limit: Upper bound for prime generation
            
        Returns:
            List of prime numbers up to limit
        """
        sieve = [True] * (limit + 1)
        sieve[0] = sieve[1] = False
        
        for i in range(2, int(math.sqrt(limit)) + 1):
            if sieve[i]:
                for j in range(i * i, limit + 1, i):
                    sieve[j] = False
        
        return [i for i in range(2, limit + 1) if sieve[i]]
    
    def is_prime(self, n: int) -> bool:
        """
        Check if a number is prime using trial division.
        
        Args:
            n: Number to check
            
        Returns:
            True if n is prime, False otherwise
        """
        if n < 2:
            return False
        if n == 2:
            return True
        if n % 2 == 0:
            return False
        
        for i in range(3, int(math.sqrt(n)) + 1, 2):
            if n % i == 0:
                return False
        return True
    
    def get_primes_in_range(self) -> List[int]:
        """
        Get all prime numbers within the specified range.
        
        Returns:
            List of primes within the range
        """
        return [p for p in self.primes_cache if self.min_range <= p <= self.max_range]
    
    def generate_key_pair(self) -> Tuple[int, int, int]:
        """
        Generate a key pair by randomly selecting two distinct prime numbers.
        This simulates the first step in RSA key generation.
        
        Returns:
            Tuple containing (p, q, n) where p and q are primes and n = p * q
        """
        available_primes = self.get_primes_in_range()
        
        if len(available_primes) < 2:
            raise ValueError(f"Not enough primes in range [{self.min_range}, {self.max_range}]")
        
        # Randomly select two distinct primes
        p, q = random.sample(available_primes, 2)
        n = p * q
        
        return p, q, n
    
    def test_key_generation(self, num_tests: int = 5) -> None:
        """
        Test the key generation algorithm multiple times.
        
        Args:
            num_tests: Number of test iterations
        """
        print("=== Prime Key Generation Algorithm Test ===")
        print(f"Algorithm Type: Probabilistic Prime Selection")
        print(f"Range: [{self.min_range}, {self.max_range}]")
        print(f"Available primes: {len(self.get_primes_in_range())}")
        print()
        
        for i in range(num_tests):
            p, q, n = self.generate_key_pair()
            print(f"Test {i+1}:")
            print(f"  p = {p} (prime: {self.is_prime(p)})")
            print(f"  q = {q} (prime: {self.is_prime(q)})")
            print(f"  n = p × q = {n}")
            print(f"  Verification: {p} × {q} = {p * q}")
            print()


class EulerTotientCalculator:
    """
    A class for calculating Euler's Totient function using different methods.
    """
    
    def __init__(self):
        pass
    
    def gcd(self, a: int, b: int) -> int:
        """
        Calculate Greatest Common Divisor using Euclidean algorithm.
        
        Args:
            a, b: Numbers to find GCD of
            
        Returns:
            GCD of a and b
        """
        while b:
            a, b = b, a % b
        return a
    
    def totient_basic(self, n: int) -> int:
        """
        Calculate Euler's Totient function using basic method.
        Count numbers from 1 to n-1 that are coprime to n.
        
        Time Complexity: O(n log log n)
        
        Args:
            n: Input number
            
        Returns:
            φ(n) - count of numbers coprime to n
        """
        if n == 1:
            return 1
        
        count = 0
        for i in range(1, n):
            if self.gcd(i, n) == 1:
                count += 1
        return count
    
    def prime_factorization(self, n: int) -> List[int]:
        """
        Find prime factors of n.
        
        Args:
            n: Number to factorize
            
        Returns:
            List of unique prime factors
        """
        factors = []
        d = 2
        while d * d <= n:
            while n % d == 0:
                if d not in factors:
                    factors.append(d)
                n //= d
            d += 1
        if n > 1:
            factors.append(n)
        return factors
    
    def totient_prime_factorization(self, n: int) -> int:
        """
        Calculate Euler's Totient function using prime factorization method.
        Uses the formula: φ(n) = n × ∏(1 - 1/p) for all prime factors p of n
        
        Time Complexity: O(√n)
        
        Args:
            n: Input number
            
        Returns:
            φ(n) using prime factorization
        """
        if n == 1:
            return 1
        
        result = n
        prime_factors = self.prime_factorization(n)
        
        for p in prime_factors:
            result = result * (p - 1) // p
        
        return result
    
    def totient_for_prime_product(self, p: int, q: int) -> int:
        """
        Calculate φ(n) for n = p × q where p and q are distinct primes.
        Uses the property: φ(p × q) = (p-1) × (q-1) when p and q are coprime.
        
        Args:
            p, q: Prime numbers
            
        Returns:
            φ(p × q)
        """
        return (p - 1) * (q - 1)
    
    def verify_multiplicative_property(self, a: int, b: int) -> Tuple[int, int, int]:
        """
        Verify that φ(a×b) = φ(a)×φ(b) when gcd(a,b) = 1.
        
        Args:
            a, b: Coprime numbers
            
        Returns:
            Tuple of (φ(a×b), φ(a)×φ(b), gcd(a,b))
        """
        if self.gcd(a, b) != 1:
            print(f"Warning: {a} and {b} are not coprime (gcd = {self.gcd(a, b)})")
        
        phi_ab = self.totient_prime_factorization(a * b)
        phi_a_times_phi_b = self.totient_prime_factorization(a) * self.totient_prime_factorization(b)
        
        return phi_ab, phi_a_times_phi_b, self.gcd(a, b)
    
    def sum_of_totients_property(self, n: int) -> Tuple[int, int]:
        """
        Verify the property: ∑φ(d) = n for all divisors d of n.
        
        Args:
            n: Input number
            
        Returns:
            Tuple of (sum of φ(d), n)
        """
        divisors = []
        for i in range(1, n + 1):
            if n % i == 0:
                divisors.append(i)
        
        sum_totients = sum(self.totient_prime_factorization(d) for d in divisors)
        return sum_totients, n
    
    def performance_comparison(self, test_values: List[int]) -> None:
        """
        Compare performance of basic vs prime factorization methods.
        
        Args:
            test_values: List of numbers to test
        """
        print("=== Performance Comparison ===")
        print(f"{'n':<10} {'Basic Method':<15} {'Prime Factor':<15} {'Speedup':<10}")
        print("-" * 55)
        
        for n in test_values:
            # Time basic method
            start_time = time.time()
            result_basic = self.totient_basic(n)
            time_basic = time.time() - start_time
            
            # Time prime factorization method
            start_time = time.time()
            result_prime = self.totient_prime_factorization(n)
            time_prime = time.time() - start_time
            
            # Verify results match
            assert result_basic == result_prime, f"Results don't match for n={n}"
            
            speedup = time_basic / time_prime if time_prime > 0 else float('inf')
            
            print(f"{n:<10} {time_basic:.6f}s{'':<4} {time_prime:.6f}s{'':<4} {speedup:.2f}x")


def main():
    """
    Main function to demonstrate key generation and Euler's Totient function.
    """
    print("=" * 80)
    
    # Section 1: Key Generation Algorithm
    print("\nPART 1: PRIME KEY GENERATION")
    print("-" * 40)
    
    key_gen = PrimeGenerator(min_range=50, max_range=200)
    key_gen.test_key_generation(num_tests=3)
    
    # Generate a key pair for use in Section 2
    p, q, n = key_gen.generate_key_pair()
    print(f"Selected key pair for Totient analysis: p={p}, q={q}, n={n}")
    
    # Section 2: Euler's Totient Function
    print("\nPART 2: EULER'S TOTIENT FUNCTION")
    print("-" * 40)
    
    totient_calc = EulerTotientCalculator()
    
    # Calculate φ(n) for the generated key
    phi_n_basic = totient_calc.totient_basic(n)
    phi_n_prime = totient_calc.totient_prime_factorization(n)
    phi_n_formula = totient_calc.totient_for_prime_product(p, q)
    
    print(f"\nEuler's Totient of n = {n}:")
    print(f"  φ({n}) using basic method: {phi_n_basic}")
    print(f"  φ({n}) using prime factorization: {phi_n_prime}")
    print(f"  φ({n}) using (p-1)×(q-1) formula: {phi_n_formula}")
    print(f"  All methods agree: {phi_n_basic == phi_n_prime == phi_n_formula}")
    
    # Performance comparison
    print(f"\nPerformance Analysis:")
    test_numbers = [30, 60, 100, 150, 200]
    totient_calc.performance_comparison(test_numbers)
    
    # Verify multiplicative property
    print(f"\nMultiplicative Property Verification:")
    test_pairs = [(3, 5), (7, 11), (p, q)]
    for a, b in test_pairs:
        phi_ab, phi_a_phi_b, gcd_ab = totient_calc.verify_multiplicative_property(a, b)
        status = "correct" if phi_ab == phi_a_phi_b else "false"
        print(f"  φ({a}×{b}) = {phi_ab}, φ({a})×φ({b}) = {phi_a_phi_b}, gcd({a},{b}) = {gcd_ab} {status}")
    
    # Sum of totients property
    print(f"\nSum of Totients Property Verification:")
    test_values = [6, 12, 24, 30]
    for n_test in test_values:
        sum_totients, n_val = totient_calc.sum_of_totients_property(n_test)
        status = "correct" if sum_totients == n_val else "false"
        print(f"  ∑φ(d) for divisors of {n_test} = {sum_totients}, n = {n_val} {status}")


if __name__ == "__main__":
    main()