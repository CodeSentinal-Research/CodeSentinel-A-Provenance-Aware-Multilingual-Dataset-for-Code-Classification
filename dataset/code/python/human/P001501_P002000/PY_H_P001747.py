"""
models.py
=========

Core, framework-agnostic code:
- Tree data model (Region → Market → Site → Attribute)
- Rule system (allow/deny + tiny DSL)
- Policy evaluation:
    * NEW: "Most-specific wins; ties deny."
      - Among rules that match a leaf path, select those with the highest specificity
        (count of constrained names across R/M/S/A).
      - If any top-specificity rule is DENY → DENY.
      - Else if any top-specificity rule is ALLOW → ALLOW.
      - Else (no matches) → DENY (default).
- Radial cluster layout (D3-like) implemented in pure Python
- Scoping helpers

RULE DSL
--------
Segments separated by "/"; each segment targets one level:

  R{R1,R2}     -> Regions in {R1,R2}
  M*           -> any Market
  S{S1,S7}     -> Sites S1 or S7
  A{"Fin Info","Latency"} -> Attributes by name (quotes allowed)

Missing segments default to "*". Whitespace is ignored around segments.

EXAMPLES
--------
Allow a single site and all attributes:
    R{R1}/M{M3}/S{S7}/A*

Blacklist Financial Info everywhere:
    R*/M*/S*/A{"Financial Information"}   (Effect.DENY)

Specific allow overriding a broader deny:
    DENY:  R*/M{M6}
    ALLOW: R*/M{M6}/S{S12}
Result: only S12 (and its attributes) in M6 is allowed.
"""

from __future__ import annotations
from dataclasses import dataclass, field
from enum import Enum
from typing import Dict, List, Optional, Tuple, Iterable, Set
import math

# ---------------------------
# Hierarchy (tree) model
# ---------------------------

class Level(str, Enum):
    REGION = "region"        # Level 0
    MARKET = "market"        # Level 1
    SITE = "site"            # Level 2
    ATTRIBUTE = "attribute"  # Level 3

LEVEL_ORDER = [Level.REGION, Level.MARKET, Level.SITE, Level.ATTRIBUTE]
LEVEL_TO_DEPTH = {lvl: i for i, lvl in enumerate(LEVEL_ORDER)}

@dataclass
class Node:
    """
    Minimal node: id, display name, level, and parent id.
    The actual tree is represented by the adjacency dict in Hierarchy.
    """
    id: str
    name: str
    level: Level
    parent_id: Optional[str] = None

@dataclass
class Hierarchy:
    """
    Flat indexes enable scale and easy rendering/scoping.
    - nodes: id -> Node
    - children: id -> [child ids]
    - root_ids: nodes without parent (Regions)
    - attribute_id_to_path: leaf attribute id -> (R,M,S,A) tuple of names
    """
    nodes: Dict[str, Node] = field(default_factory=dict)
    children: Dict[str, List[str]] = field(default_factory=dict)
    root_ids: List[str] = field(default_factory=list)
    attribute_id_to_path: Dict[str, Tuple[str, str, str, str]] = field(default_factory=dict)

    # Quick name->id indexes (optional but handy)
    regions_by_name: Dict[str, Set[str]] = field(default_factory=dict)
    markets_by_name: Dict[str, Set[str]] = field(default_factory=dict)
    sites_by_name: Dict[str, Set[str]] = field(default_factory=dict)
    attributes_by_name: Dict[str, Set[str]] = field(default_factory=dict)

    def add(self, node: Node) -> None:
        self.nodes[node.id] = node
        if node.parent_id:
            self.children.setdefault(node.parent_id, []).append(node.id)
        else:
            self.root_ids.append(node.id)

        # name indexes
        if node.level == Level.REGION:
            self.regions_by_name.setdefault(node.name, set()).add(node.id)
        elif node.level == Level.MARKET:
            self.markets_by_name.setdefault(node.name, set()).add(node.id)
        elif node.level == Level.SITE:
            self.sites_by_name.setdefault(node.name, set()).add(node.id)
        elif node.level == Level.ATTRIBUTE:
            self.attributes_by_name.setdefault(node.name, set()).add(node.id)

    def _lineage_names(self, leaf_id: str):  # -> List[str]
        """Return [R, M, S, A] names for an attribute leaf id."""
        out: List[str] = []
        cur = self.nodes[leaf_id]
        while cur:
            out.append(cur.name)
            cur = self.nodes[cur.parent_id] if cur.parent_id else None
        out.reverse()
        return out

    def build_attribute_paths(self) -> None:
        self.attribute_id_to_path.clear()
        for n in self.nodes.values():
            if n.level == Level.ATTRIBUTE:
                names = self._lineage_names(n.id)
                if len(names) == 4:
                    self.attribute_id_to_path[n.id] = tuple(names)  # (R, M, S, A)

    def iter_paths(self):  # -> Iterable[Tuple[str,str,str,str]]
        """Iterate all leaf paths (R, M, S, A)."""
        return self.attribute_id_to_path.values()

# ---------------------------
# Rules & evaluation
# ---------------------------

class Effect(str, Enum):
    ALLOW = "allow"
    DENY = "deny"

@dataclass(frozen=True)
class Selector:
    """
    Per-level selector: either '*' (all=True) or a frozen set of names.
    Specificity: number of constrained names (0 for '*').
    """
    all: bool = False
    values: frozenset[str] = frozenset()

    @staticmethod
    def all_of() -> "Selector":
        return Selector(all=True, values=frozenset())

    @staticmethod
    def of(values: Iterable[str]) -> "Selector":
        return Selector(all=False, values=frozenset(values))

    def matches(self, value: str) -> bool:
        return self.all or value in self.values

    # NEW: used for most-specific-wins
    def specificity(self) -> int:
        return 0 if self.all else len(self.values)

@dataclass(frozen=True)
class Rule:
    """Structured rule across 4 levels."""
    effect: Effect
    region: Selector
    market: Selector
    site: Selector
    attribute: Selector
    label: str = ""

    def matches_path(self, path: Tuple[str, str, str, str]) -> bool:
        r, m, s, a = path
        return (self.region.matches(r) and
                self.market.matches(m) and
                self.site.matches(s) and
                self.attribute.matches(a))

    # NEW: combined specificity across all levels
    def specificity(self) -> int:
        return (self.region.specificity()
                + self.market.specificity()
                + self.site.specificity()
                + self.attribute.specificity())

@dataclass
class Role:
    """A role is a set of rules. Policy = Most-specific wins; ties deny."""
    name: str
    rules: List[Rule] = field(default_factory=list)

    def is_allowed(self, path: Tuple[str, str, str, str]) -> bool:
        matches = [r for r in self.rules if r.matches_path(path)]
        if not matches:
            return False  # default deny

        # Choose rules with maximum specificity
        max_spec = max(r.specificity() for r in matches)
        top = [r for r in matches if r.specificity() == max_spec]

        # Tie-break: if any DENY at top specificity, deny; else allow
        has_deny = any(r.effect == Effect.DENY for r in top)
        has_allow = any(r.effect == Effect.ALLOW for r in top)
        return has_allow and not has_deny

# ---- DSL parsing ----

def parse_rule_dsl(expr: str, effect: Effect, label: str = "") -> Rule:
    """
    Parse DSL into a Rule.
    Grammar (loose):
      Segment := [R|M|S|A] ("*" | "{" values "}")
      values  := value ("," value)*
      value   := identifier | quoted string (quotes required when commas or spaces)
    Missing segments default to '*'.
    """
    # defaults to ALL
    sel = {
        Level.REGION: Selector.all_of(),
        Level.MARKET: Selector.all_of(),
        Level.SITE: Selector.all_of(),
        Level.ATTRIBUTE: Selector.all_of(),
    }

    def unq(x: str) -> str:
        x = x.strip()
        if len(x) >= 2 and x[0] == '"' and x[-1] == '"':
            return x[1:-1]
        return x

    if expr.strip():
        for seg in expr.split('/'):
            seg = seg.strip()
            if not seg:
                continue
            L = seg[0].upper()
            body = seg[1:].strip()
            if body == '*':
                values = None
            else:
                if not (body.startswith('{') and body.endswith('}')):
                    raise ValueError(f"Bad segment: {seg}")
                inner = body[1:-1].strip()
                if not inner:
                    values = []
                else:
                    parts, buf, in_q = [], "", False
                    for ch in inner:
                        if ch == '"':
                            in_q = not in_q
                            buf += ch
                        elif ch == ',' and not in_q:
                            parts.append(buf.strip()); buf = ""
                        else:
                            buf += ch
                    if buf:
                        parts.append(buf.strip())
                    values = [unq(p) for p in parts]

            selector = Selector.all_of() if values is None else Selector.of(values)
            if L == 'R':
                sel[Level.REGION] = selector
            elif L == 'M':
                sel[Level.MARKET] = selector
            elif L == 'S':
                sel[Level.SITE] = selector
            elif L == 'A':
                sel[Level.ATTRIBUTE] = selector
            else:
                raise ValueError(f"Unknown level: {L}")

    return Rule(effect=effect,
                region=sel[Level.REGION],
                market=sel[Level.MARKET],
                site=sel[Level.SITE],
                attribute=sel[Level.ATTRIBUTE],
                label=label)

# ---------------------------
# Radial cluster layout
# ---------------------------

@dataclass
class RadialLayout:
    pos: Dict[str, Tuple[float, float]]  # node_id -> (x, y)
    theta: Dict[str, float]              # node_id -> angle (radians)
    radius: Dict[str, float]             # node_id -> radius

def _get_leaves(h: Hierarchy, nid: str) -> List[str]:
    if nid not in h.children:
        # leaf if ATTRIBUTE; else empty
        return [nid] if h.nodes[nid].level == Level.ATTRIBUTE else []
    out: List[str] = []
    for cid in h.children[nid]:
        out.extend(_get_leaves(h, cid))
    return out

def radial_cluster_layout(h: Hierarchy, r_gap: float = 1.0,
                          start_angle: float = -math.pi/2, end_angle: float = 3*math.pi/2) -> RadialLayout:
    """
    D3-ish radial cluster:
      - leaves share equal angular slots over [start_angle, end_angle)
      - internal nodes sit at the mean of child angles
      - radius increases by fixed gap per depth
    """
    # collect leaf list in a stable order
    leaves: List[str] = []
    for root in h.root_ids:
        leaves.extend(_get_leaves(h, root))
    if not leaves:
        return RadialLayout(pos={}, theta={}, radius={})

    L = len(leaves)
    angle_span = end_angle - start_angle
    leaf_angles = {leaf: (start_angle + i * angle_span / L) for i, leaf in enumerate(leaves)}

    theta: Dict[str, float] = {}
    radius: Dict[str, float] = {}

    def assign(nid: str) -> None:
        node = h.nodes[nid]
        depth = LEVEL_TO_DEPTH[node.level]
        radius[nid] = (depth + 1) * r_gap
        if nid in leaf_angles:
            theta[nid] = leaf_angles[nid]
        else:
            kids = h.children.get(nid, [])
            if not kids:
                theta[nid] = start_angle
            else:
                for c in kids:
                    assign(c)
                theta[nid] = sum(theta[c] for c in kids) / len(kids)

    for root in h.root_ids:
        assign(root)

    pos: Dict[str, Tuple[float, float]] = {nid: (radius[nid] * math.cos(theta[nid]),
                                                 radius[nid] * math.sin(theta[nid]))
                                            for nid in theta}
    return RadialLayout(pos=pos, theta=theta, radius=radius)

# ---------------------------
# Scoping helper
# ---------------------------

# --- add these helpers near your Rule/Role code ---

def _prefix_names_for_node(h: Hierarchy, nid: str) -> Tuple[str, ...]:
    """Return the name prefix tuple for this node level:
       Region -> (R,)
       Market -> (R,M)
       Site   -> (R,M,S)
       Attr   -> (R,M,S,A)
    """
    names: list[str] = []
    cur = h.nodes[nid]
    while cur:
        names.append(cur.name)
        cur = h.nodes[cur.parent_id] if cur.parent_id else None
    names.reverse()
    return tuple(names)

def _rule_matches_prefix(rule: Rule, prefix: Tuple[str, ...]) -> bool:
    """
    Does rule match this node prefix (ignores deeper levels)?
    IMPORTANT: a rule may only influence a prefix of length k
    if ALL selectors deeper than k are '*' (unconstrained).
    This prevents attribute-only rules from hiding higher levels.
    """
    prefix_len = len(prefix)

    # 1) Require deeper selectors to be '*' for shorter prefixes
    if prefix_len < 4 and not rule.attribute.all:
        return False
    if prefix_len < 3 and not rule.site.all:
        return False
    if prefix_len < 2 and not rule.market.all:
        return False

    # 2) Match the available components
    if prefix_len >= 1:
        r = prefix[0]
        if not rule.region.matches(r):
            return False
    if prefix_len >= 2:
        m = prefix[1]
        if not rule.market.matches(m):
            return False
    if prefix_len >= 3:
        s = prefix[2]
        if not rule.site.matches(s):
            return False
    if prefix_len >= 4:
        a = prefix[3]
        if not rule.attribute.matches(a):
            return False

    return True


def _rule_specificity_for_prefix(rule: Rule, prefix_len: int) -> int:
    """Specificity restricted to the first N levels (prefix length)."""
    spec = 0
    if prefix_len >= 1: spec += rule.region.specificity()
    if prefix_len >= 2: spec += rule.market.specificity()
    if prefix_len >= 3: spec += rule.site.specificity()
    if prefix_len >= 4: spec += rule.attribute.specificity()
    return spec

# --- replace your visibility collector with this ---

def collect_visible_nodes_from_role(
    h: Hierarchy,
    role: Role,
    include_roots: bool = False
) -> Set[str]:
    """
    Visibility = (A ∪ B)
      A: all ancestors of leaf paths ALLOWED by role.is_allowed(path)
      B: any node whose own prefix is ALLOWED by the most-specific matching rule
         at that prefix (ties DENY). This keeps Regions/Markets/Sites visible
         under rules like ALLOW R* or ALLOW R*/M*/S*/A{"Latency"} even when
         deeper levels are missing.
    """
    visible: Set[str] = set()

    # A) Ancestors of allowed leaves (uses full-path evaluator)
    allowed_paths: Set[Tuple[str, str, str, str]] = {p for p in h.iter_paths() if role.is_allowed(p)}
    path_to_attr_ids: Dict[Tuple[str, str, str, str], List[str]] = {}
    for aid, p in h.attribute_id_to_path.items():
        path_to_attr_ids.setdefault(p, []).append(aid)

    for path in allowed_paths:
        for aid in path_to_attr_ids.get(path, []):
            cur = aid
            while cur and cur not in visible:
                visible.add(cur)
                cur = h.nodes[cur].parent_id

    # B) Nodes explicitly allowed at their prefix (even without descendants)
    for nid in h.nodes:
        prefix = _prefix_names_for_node(h, nid)
        matches = [r for r in role.rules if _rule_matches_prefix(r, prefix)]
        if not matches:
            continue
        # most-specific wins at this prefix (ties deny)
        max_spec = max(_rule_specificity_for_prefix(r, len(prefix)) for r in matches)
        top = [r for r in matches if _rule_specificity_for_prefix(r, len(prefix)) == max_spec]
        if any(r.effect == Effect.DENY for r in top):
            # explicitly denied at this prefix -> not visible (unless made visible via A)
            continue
        if any(r.effect == Effect.ALLOW for r in top):
            visible.add(nid)

    if include_roots:
        visible.update(h.root_ids)

    return visible
