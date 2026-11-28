from __future__ import annotations
from fractions import Fraction
from math import comb, gcd, prod, sqrt

from ..arithmetic.common import legendre, kronecker, factorize, valuation as vl, divisors
from ..arithmetic.forms import BinaryQuadraticForm
from ..arithmetic.quadratic import LatticeTower, QuadraticOrderElement
from ..arithmetic.function import phi, Phi, KroneckerCharacter
from ..config import get_config, get_pari

""" Group structure helper functions """
def C_ell(l: int, a: int, inv: tuple[int, int]) -> int:
    """Number of cyclic subgroups of order l^a in Z/l^e1 x Z/l^e2."""
    e1, e2 = inv
    if e2 < a:
        return 0
    if e1 < a:
        return l ** e1
    return phi(-1)(l ** a)

def P_ell(ell: int, a: int, inv: tuple[int, int]) -> int:
    """Number of elements of exact order ell^a in Z/ell^e1 x Z/ell^e2."""
    e1, e2 = inv
    s1 = min(a, e1)
    s2 = min(a, e2)
    return ell ** (s1 + s2) - ell ** (min(a - 1, s1) + min(a - 1, s2))


def P_N(N: int, inv: tuple[int, int]) -> int:
    """Number of elements of exact order N in Z/d1 x Z/d2."""
    d1, d2 = inv
    if d2 < N:
        return 0
    return prod(P_ell(ell, a, (vl(d1, ell), vl(d2, ell))) for ell, a in factorize(N))

""" Class number helper function """
# TODO: implement precomputation for class numbers

def hOK(D):
    pari = get_pari()
    if pari:
        return int(pari.qfbclassno(D))
    return BinaryQuadraticForm.h(D)

WeilDatum = tuple[int, LatticeTower]

def enum_weil_q(p: int, n: int, N: int) -> list[WeilDatum]:
    """Enumerate the trace strata `(t, tower)` over `F_{p^n}`."""
    lattices: list[WeilDatum] = []
    q = p ** n
    HB = int(2 * sqrt(q))
    config = get_config()
    pari = get_pari()

    def has_torsion(t: int) -> bool:
        return (q + 1 - t) % N == 0

    def is_valid(D:int, t: int) -> bool:
        d = 1 - legendre(D, p) if t % p == 0 else 1
        return d != 0

    def twists_for_t(t: int, filter_torsion:bool = False) -> list[int]:
        if filter_torsion:
            return [s*t for s in ((1, -1) if t != 0 else (1,)) if has_torsion(s * t)]
        return [s*t for s in ((1, -1) if t != 0 else (1,))]

    def get_tower_over_K(D: int) -> LatticeTower:
        result: list[WeilDatum] = []
        DK, f_pi = BinaryQuadraticForm._D0(D, pari=pari)
        lattice_tower = LatticeTower(DK, f_pi, exclude=p)
        return lattice_tower

    def get_datum_over_t(t: int, signed_traces: list[int]) -> list[WeilDatum]:
        if not signed_traces:
            return []
        D = t * t - 4 * q
        # t^2 <= 4q already satisfied, but we need to filter out bad t for p | t
        # TODO: Make sure this agrees on D = DK
        if not is_valid(D, t):
            return []
        # compute the frobenius lattice tower over K, once per abs t and reuse
        lattice_tower = get_tower_over_K(D)
        return [(t, lattice_tower) for t in signed_traces]

    def trace_classes(q, N, HB):
        """{t: [signs]} for 0 <= t <= HB with N | q+1-s*t."""
        rp, rm = (q + 1) % N, (-(q + 1)) % N
        signs = {}
        for t in range(rp, HB + 1, N):
            signs.setdefault(t, []).append(1)
        for t in range(rm, HB + 1, N):
            signs.setdefault(t, []).append(-1)
        return signs, rp, rm

    use_fast_trace = config.fast_trace
    if use_fast_trace:
        vals, rp, rm = trace_classes(q, N, HB)
        for t in vals:
            lattices.extend(get_datum_over_t(t, [s * t for s in vals[t]] if t else [0]))
    else:
        for t in range(0, HB + 1):
            lattices.extend(get_datum_over_t(t, twists_for_t(t, filter_torsion=True)))
    # lattices.sort(key=lambda x: x[0])
    return lattices

class X1:
    """The modular curve `X_1(N)` with fixed level."""

    def __init__(self, N: int):
        self.N = N

    def over(self, p: int, n: int) -> "X1Fq":
        return X1Fq(self, p, n)


class X1Fq:
    """The `F_q`-rational point count of `X_1(N)` stratified by trace."""

    def __init__(self, moduli: X1, p: int, n: int):
        self.N, self.p, self.n, self.q = moduli.N, p, n, p ** n

    def y1(self):
        for t, lattice_tower in enum_weil_q(self.p, self.n, self.N):
            yield Y1Fq(self.N, self.p, self.n, t, lattice_tower)

    def cusps(self):
        for s in (1, -1):
            yield Cusp1Fq(self, s)

    def count(self):
        return (
            sum(st.count() for st in self.y1()),
            sum(st.count() for st in self.cusps()),
        )


class Y1Fq:
    """A single `Y_1(N)(F_q)` trace stratum attached to `t`."""

    def __init__(self, N: int, p: int, n: int, t: int, lattice: LatticeTower):
        self.N, self.q, self.t = N, p ** n, t
        self.lattice = lattice
        self.p = p
        self.n = n
        self.DK = lattice.DK

        m_K = hOK(self.DK) if self.DK != 0 else (p-1)
        u_K = 2 * (2 if self.DK == -4 else 3 if self.DK == -3 else 12 if self.DK == 0 else 1)
        d = 1 - legendre(self.DK, p) if t % p == 0 else 1
        self.m0 = Fraction(m_K * d, u_K)

        # create the Frobenius element (pi-1) in the quadratic order
        pi_form = BinaryQuadraticForm(1, t, self.q)
        self.frob_1 = QuadraticOrderElement.from_norm_form(
            self.lattice.OK, pi_form, shift=-1
        )

        """
        Debug (pi-1) coords
        f_pi = lattice.f_max
        a_pi = (self.t - lattice.f_max) // 2 if self.DK % 4 == 1 else (self.t // 2)
        pi1_coords = (a_pi-1, f_pi)
        if pi1_coords[0] != self.frob_1.coords[0] or pi1_coords[1] != self.frob_1.coords[1]:
            raise ValueError("WARNING: pi_coords do not match frob.coords")
        """

        self.chi_K = KroneckerCharacter(self.DK)

    def inv_ell(self, l: int, i: int) -> tuple[int, int]:
        # These are the local invariant exponents of the `ell`-primary quotient.
        e1 = min(vl(self.frob_1.u, l), i)
        e2 = vl(self.frob_1.norm, l) - e1
        return (e1, e2)

    def inv(self, f: int) -> tuple[int, int]:
        d1 = gcd(self.frob_1.u, self.frob_1.v // f)
        d2 = self.frob_1.norm // d1
        return (d1, d2)

    def value_at_ell(self, l: int, a: int, i: int, h:int ) -> int:
        return C_ell(l, a, self.inv_ell(l, h-i)) * phi(
            self.chi_K
        )(l ** i)

    def tower_sum_ell(self, l: int, a: int, k: int, h:int) -> int:
        return sum(self.value_at_ell(l, a, i, h) for i in range(0, k + 1))

    def conductor_divisors(self, conductors: dict[int, int] | None = None) -> list[int]:
        if conductors is None:
            conductors = self.lattice.conductors
        divs = [1]
        for l, k in conductors.items():
            if l == 1:
                continue
            divs = [d * (l ** i) for d in divs for i in range(k + 1)]
        return divs

    def count(self) -> Fraction:
        # store a local copy of the conductor exponents for manipulation
        conductors = dict(self.lattice.conductors)
        lattice_sum = (
            # SUM f | f_pi factors as prod l^a | N SUM i^k contrib at Of=l^i
            prod(
                sum(
                    # h(f) * C_ell^a(f_pi/f)
                    phi(self.chi_K)(l**i)
                    * C_ell(l, a, self.inv_ell(l, vl(self.frob_1.v, l) - i))
                    # TODO: vl(f_pi) = vl(self.frob_1.v, l) = k in all cases except when p | f_pi
                    for i in range(0, conductors.pop(l, 0) + 1)
                )
                for l, a in factorize(self.N)
            )
            # multiply the nr of cyclic subgroups of order l^a with phi(N)
            * phi(1)(self.N)
            # multiply the leftover coprime tower divisor sum
            * Phi(self.chi_K, prod(l**a for l, a in conductors.items()))
        )
        # return the final value multiplied by the base lattice mass
        return lattice_sum * self.m0

        """ 
        For debug, use this which computes the lattice sum explicitly rather than using the flattened tower sum. 
            tower_divisors = self.conductor_divisors(conductors)
            lattice_sum = 0
            for f in tower_divisors:
                inv = self.inv(f)
                e = phi(self.chi_K)(f)
                NP = P_N(self.N, inv)
                lattice_sum += e * NP
            return lattice_sum * self.m0

        return (
            self.m0
            * phi(1)(self.N)
            * prod(
                self.tower_sum_ell(l, a, conductors.pop(l, 0))
                for l, a in factorize(self.N)
            )
            * Phi(self.chi_K, prod(l ** a for l, a in conductors.items()))
        )"""


class Cusp1Fq:
    """The split or nonsplit cusp contribution."""

    def __init__(self, base: X1Fq, t: int):
        self.N, self.q, self.p = base.N, base.q, base.p
        self.t = t

    def count(self):
        num_split = 0
        num_non_split = 0
        if self.t == 1:
            num_split = sum(
                phi(1)(d) * phi(1)(Nd)
                for d in divisors(self.N)
                for Nd in [self.N // d]
                if (self.q - 1) % Nd == 0
            )
        elif self.t == -1:
            for d in (1, 2):
                if self.N % d != 0:
                    continue
                e = self.N // d
                if (self.q + 1) % e == 0:
                    num_non_split += phi(1)(d) * phi(1)(e)
        return Fraction(num_split + num_non_split, 2)
