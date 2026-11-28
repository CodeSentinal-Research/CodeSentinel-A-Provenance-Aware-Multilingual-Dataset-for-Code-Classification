package jeff.coalroutegenerator.client.route;

/**
 * What a second of mining time is spent on. Phase 3's differentiator, per the
 * roadmap: a mediocre solver with correct weights beats a perfect solver with
 * Euclidean distance.
 *
 * <p>Everything here is either measured or labelled as an estimate. The measured
 * numbers came from the user's stopwatch on 2026-08-22 and from
 * {@code /crg debug segments}; the estimates are the climb surcharge and the mining
 * rate, and both are isolated here so retuning them is a one-line change.
 */
public final class CostModel {
	/**
	 * <b>Timed by the user on Hypixel, 2026-08-22</b>, over 20 blocks with the
	 * real mining loadout: 3.2-3.5 s to dig through, 1.0-1.3 s to run across,
	 * about 0.3 s to teleport. Per block a run costs under a third of a dig.
	 */
	public static final double DIG_SECONDS_PER_BLOCK = 3.35 / 20.0;

	public static final double RUN_SECONDS_PER_BLOCK = 1.15 / 20.0;

	/**
	 * How far one vein-to-vein hop may reach.
	 *
	 * <p>Q8 measured a median nearest neighbour of 8 blocks and found three veins
	 * in ~15,000 beyond 20, which is where the user's "never more than about 20
	 * blocks" came from. <b>That 20 is a guideline, not a rule</b>, and this was
	 * treating it as one: a 21-block hop to an excellent vein is a 21-block hop,
	 * and this model already charges every block of it. The cap exists to keep
	 * the graph sparse, not to express a preference, so it sits a little past the
	 * observed spread and lets {@link #hopSeconds} decide whether the distance is
	 * worth paying. Widening 20 to 24 costs about 1.7x the candidate edges - a
	 * few hundred milliseconds once per scan.
	 */
	public static final int HOP_CAP = 24;

	/**
	 * How far the <b>approach into the route</b> may reach from the player. Not a
	 * hop, and not capped like one.
	 *
	 * <p>The whole point of routing from the Crystal Nucleus is that the coal is
	 * somewhere else - a drop down into the Magma Fields, tens of blocks away.
	 * Priced with {@link #HOP_CAP} the answer was always "no coal veins within 20
	 * blocks", which is true and useless. This reaches across the loaded region
	 * instead and lets {@link #entrySeconds} charge for the distance.
	 */
	public static final int ENTRY_REACH = 160;

	/**
	 * <b>Estimate.</b> Falling is the cheapest movement in the game and the
	 * Nucleus descent is built on it: no mining, no walking, and the player is
	 * 60 blocks lower. Charged at a token rate rather than zero so that between
	 * two equally good entries, the shallower one wins.
	 */
	public static final double FALL_SECONDS_PER_BLOCK = 0.02;

	/**
	 * <b>Estimate.</b> What one blocker on the approach costs to walk around.
	 *
	 * <p>On a hop this is a refusal - {@link LineProbe#between} deletes the edge -
	 * because at 8 blocks a gemstone cluster on the line really does separate two
	 * veins. Over a hundred-block approach it separates nothing; you go round it.
	 * Four blocks of digging is the sidestep the roadmap's phase 4 already talks
	 * about hinting at.
	 */
	public static final double SIDESTEP_SECONDS = 4 * DIG_SECONDS_PER_BLOCK;

	/**
	 * <b>Climbing is a renewal process, not a per-block cost.</b>
	 *
	 * <p>The old model climbed by digging a foothold and teleporting onto it every
	 * three blocks. The user told us on 2026-08-26 they do not climb that way, and
	 * the teleport it rested on has been withdrawn from this class. They climb the
	 * way Q15 describes: look steeply up, dig a diagonal tunnel, and hold jump under
	 * Jump Boost IV, which lifts them about five blocks "at a time. But sometimes it
	 * fails."
	 *
	 * <p>Two facts follow, and neither survives a linear per-block charge:
	 * <ul>
	 * <li><b>Cost is quantised per jump.</b> One cycle buys its height whether you
	 *     needed one block or five, so a vein a single block overhead still costs a
	 *     whole cycle.
	 * <li><b>The rise a cycle buys has a failure tail.</b> A share of cycles gain
	 *     nothing and are retried, so the number of cycles to climb a height is a
	 *     renewal process, not a division: {@code ceil(rise / risePerCycle)}
	 *     successful cycles, inflated by {@code 1 / (1 - failureRate)} for the
	 *     misses. Twelve blocks is not twelve over the mean - see
	 *     {@link #climbSeconds}.
	 * </ul>
	 *
	 * <p>All three numbers are <b>estimates from the user's stated loadout</b>, not
	 * measurements. They are volatile and exposed under Route -&gt; Your mining
	 * speed so a different Jump Boost level does not need a recompile, and so the
	 * {@code cycles.csv} histogram {@code client.telemetry} records can replace them
	 * without one: its report already prints each measured value beside the constant
	 * in use.
	 *
	 * <p>{@code climbRisePerCycle} is the rise a <i>successful</i> cycle buys - the
	 * quantum {@code ceil} rounds up to - not the mean over all attempts, which the
	 * failure rate already accounts for separately.
	 */
	private static volatile double climbRisePerCycle = 5.0;

	private static volatile double climbFailureRate = 0.2;

	/**
	 * The <b>marginal</b> seconds one climbing cycle adds on top of tunnelling
	 * forward, so it must not be set to a measured whole-cycle duration: an
	 * airborne stretch also carries horizontal progress that {@link #hopSeconds}
	 * already charges as rock, and folding that in here would double-count it. The
	 * telemetry report flags exactly this by printing air-tunnel against
	 * ground-tunnel; the gap between them is what belongs here.
	 */
	private static volatile double climbSecondsPerCycle = 0.5;

	/**
	 * Coal ore is instant-mine like every other ore (roadmap section 4), so
	 * clearing a vein is not limited by hardness but by repositioning and ping -
	 * the same thing that limits digging a tunnel. So one <i>break</i> costs what
	 * one block of tunnel costs.
	 *
	 * <p>How many coal blocks that break destroys is {@link #blocksPerBreak()}.
	 */
	public static final double SECONDS_PER_BREAK = DIG_SECONDS_PER_BLOCK;

	/**
	 * Hypixel's mining-spread stat, on <b>ore</b>. Reported by the user
	 * 2026-08-22: 460 spread on ores, which breaks 4 additional blocks always and
	 * a 5th 60% of the time.
	 *
	 * <p>The stat reads as {@code 100 x blocks}: 460 is "4.6 extra blocks", paid
	 * out as 4 guaranteed plus a 0.6 chance of one more. The block you aimed at
	 * is not part of the stat, so the expected yield of one break is
	 * {@code 1 + 4.6}.
	 */
	public static final double ORE_SPREAD_BLOCKS = 4.6;

	/**
	 * The same stat on <b>hard stone</b> - stone, cobblestone, gray wool and the
	 * terracotta family, which is nearly everything the Hollows are made of. The
	 * user has 860: 8 extra blocks always, a 9th 60% of the time.
	 *
	 * <p>Not used in a cost, and kept only so the two stats sit together.
	 * <b>Spread never crosses block types</b> - user, 2026-08-22: breaking stone
	 * spreads into stone only, breaking coal into coal only. So the wide stone
	 * cross-section takes no coal with it, and this number cannot make a vein
	 * cheaper, reveal one, or damage one.
	 *
	 * <p>It does not make {@link #DIG_SECONDS_PER_BLOCK} cheaper either. That was
	 * timed through this same gear, and a wider tunnel is not a shorter one.
	 */
	public static final double STONE_SPREAD_BLOCKS = 9.6;

	/**
	 * How many coal blocks one break destroys, with the player's area-mining
	 * perks - Mole, Mining Spread - applied.
	 *
	 * <p><b>Raised by the user, 2026-08-22:</b> "I have Heart of the Mountain
	 * mole perk maxed out and mining spread maxed out so I break lots of blocks
	 * at once." The model charged every coal block as its own break, which for
	 * that loadout overcharges a big vein by whatever the real figure is - and
	 * <b>that term is what decides the whole route</b>, because it is the only
	 * thing weighing a vein's size against the cost of reaching it. Overcharge
	 * it and the router prefers many small veins; price it right and it prefers
	 * a few large ones.
	 *
	 * <p>Note this does <i>not</i> apply to {@link #DIG_SECONDS_PER_BLOCK}. That
	 * was timed by the user through their own gear, and it is a <i>tunnel</i>:
	 * breaking sideways does not move you forward, so area mining does not make
	 * a tunnel shorter. Clearing a vein is a volume, and a volume is exactly what
	 * area mining helps with. The two numbers are separate on purpose.
	 *
	 * <p><b>No longer a guess.</b> The default was 1.0 - the old behaviour -
	 * until the user gave the stat on 2026-08-22. It is now
	 * {@code 1 + }{@link #ORE_SPREAD_BLOCKS}, the expected blocks per break when
	 * the block you aim at is coal.
	 *
	 * <p><b>Whether it is exact or an upper bound depends on a mechanic nobody
	 * here knows.</b> The user has confirmed spread never crosses block types -
	 * coal spreads into coal only - but not whether it picks a fixed shape around
	 * the aimed block and drops the parts that are not coal, or seeks out the
	 * nearest coal until it has its quota. If it drops, 5.6 is a ceiling reached
	 * only inside a vein and missed on its surface, which biases the router
	 * slightly towards big veins. If it seeks, 5.6 is exact for any vein with 5.6
	 * coal in reach and the model is already right. {@link #mineSeconds} charges
	 * a minimum of one break either way, so a vein smaller than the spread is
	 * never free. Override it under Route -> Your mining speed in {@code /crg
	 * config} if a timed vein disagrees; the screen saves, so it survives a
	 * restart.
	 */
	private static volatile double blocksPerBreak = 1.0 + ORE_SPREAD_BLOCKS;

	private CostModel() {
	}

	public static double blocksPerBreak() {
		return blocksPerBreak;
	}

	/** @param blocks coal destroyed per break; clamped to at least one */
	public static void blocksPerBreak(double blocks) {
		blocksPerBreak = Math.max(1.0, blocks);
	}

	/**
	 * The cost of one hop, in seconds.
	 *
	 * <p>Directed on purpose. The rock is the same in both directions and is
	 * charged the same, but the climb is not: falling down a tunnel you dug is
	 * free, and climbing the same tunnel costs a jump-boost cycle for every
	 * {@link #climbRisePerCycle()} blocks of rise. This is the vertical asymmetry
	 * the roadmap calls out, expressed as the thing that actually causes it rather
	 * than as a multiplier on {@code dy}.
	 *
	 * @param dug blocks of mineable rock on the line
	 * @param air air blocks on the line, crossed at running pace
	 * @param rise net climb in blocks; zero or less costs nothing extra
	 * @param landable whether the destination vein has standable air against it,
	 *     which saves the last foothold because there is somewhere to arrive
	 */
	public static double hopSeconds(int dug, int air, int rise, boolean landable) {
		double seconds = dug * DIG_SECONDS_PER_BLOCK + air * RUN_SECONDS_PER_BLOCK;
		if (rise > 0) {
			seconds += climbSeconds(rise, landable);
		}
		return seconds;
	}

	/**
	 * The cost of getting from the player into the route, in seconds.
	 *
	 * <p>Two things make this different from {@link #hopSeconds}, and both come
	 * from the same fact: the approach is long.
	 *
	 * <ul>
	 * <li><b>Descending air is nearly free, not run-priced.</b> A hop is
	 *     effectively flat, so its air is walked. An approach from the Nucleus is
	 *     a drop, and a drop costs nothing but the landing.
	 * <li><b>Blockers are detours, not refusals.</b> See
	 *     {@link LineProbe#approach}.
	 * </ul>
	 *
	 * @param dug blocks of mineable rock on the line, plus anything outside the snapshot
	 * @param air air blocks on the line
	 * @param detours impassable blocks to walk around
	 * @param rise net climb in blocks; negative is a drop
	 * @param landable whether the destination vein has standable air against it
	 */
	public static double entrySeconds(int dug, int air, int detours, int rise, boolean landable) {
		double seconds = dug * DIG_SECONDS_PER_BLOCK + detours * SIDESTEP_SECONDS;
		if (rise > 0) {
			seconds += air * RUN_SECONDS_PER_BLOCK + climbSeconds(rise, landable);
		} else {
			seconds += air * FALL_SECONDS_PER_BLOCK;
		}
		return seconds;
	}

	/**
	 * What climbing {@code rise} blocks costs, as a renewal process over jump
	 * cycles rather than a linear per-block charge. See the field group above for
	 * why: the height comes in quantised jumps, and a share of those jumps fail.
	 *
	 * <p>{@code ceil(rise / risePerCycle)} successful cycles carry the height, so
	 * even one block overhead costs a whole cycle. Collecting that many successes
	 * when each cycle succeeds with probability {@code 1 - failureRate} takes
	 * {@code successes / (1 - failureRate)} cycles on average - the failure tail
	 * inflates the count, and it is why twelve blocks costs more than twelve over
	 * the mean rise would suggest.
	 *
	 * @param rise net climb in blocks; zero or less costs nothing
	 * @param landable whether the destination vein has standable air against it,
	 *     which saves the final cycle because there is somewhere to arrive
	 */
	public static double climbSeconds(int rise, boolean landable) {
		if (rise <= 0) {
			return 0.0;
		}
		int successes = (int) Math.ceil(rise / climbRisePerCycle);
		if (landable) {
			successes--;
		}
		if (successes <= 0) {
			return 0.0;
		}
		double expectedCycles = successes / (1.0 - climbFailureRate);
		return expectedCycles * climbSecondsPerCycle;
	}

	public static double climbRisePerCycle() {
		return climbRisePerCycle;
	}

	/** @param blocks rise one successful jump buys; clamped to at least one */
	public static void climbRisePerCycle(double blocks) {
		climbRisePerCycle = Math.max(1.0, blocks);
	}

	public static double climbFailureRate() {
		return climbFailureRate;
	}

	/** @param share fraction of jumps that gain nothing; clamped to [0, 0.95] */
	public static void climbFailureRate(double share) {
		climbFailureRate = Math.max(0.0, Math.min(0.95, share));
	}

	public static double climbSecondsPerCycle() {
		return climbSecondsPerCycle;
	}

	/** @param seconds marginal cost of one climb jump; clamped to zero or more */
	public static void climbSecondsPerCycle(double seconds) {
		climbSecondsPerCycle = Math.max(0.0, seconds);
	}

	/**
	 * The share of candidate hops that a live probe refuses outright.
	 *
	 * <p><b>Measured by {@code /crg debug segments}, three runs:</b> 11% of candidates,
	 * stable across the Magma Fields and the Nucleus. An edge priced from the
	 * average rather than probed has not had that filter applied to it, so it is
	 * loaded by the odds that a probe would have refused it. Without this an
	 * unmeasured edge would look <i>better</i> than a measured one, and the router
	 * would systematically prefer the parts of the map it cannot see.
	 */
	public static final double UNKNOWN_REFUSAL_SHARE = 0.11;

	/**
	 * What a hop costs when there is no terrain to probe.
	 *
	 * <p>This is what makes a cached lobby routable. {@code scan.CoalCache} holds
	 * coal for the whole lobby, but terrain only exists inside the window the
	 * client currently has loaded, so a hop between two cached veins outside it
	 * cannot be probed. The old behaviour was to delete such an edge, which turns
	 * every vein outside the window into an island.
	 *
	 * <p><b>It is an estimate, but not a guess.</b> Q6 measured the straight line
	 * between two nearby veins as <b>98.8% rock</b> - 0.135 air blocks on an
	 * 11.4-block line, twelve times depleted against the 15.3% air of the shell -
	 * and 97% of lines held no air at all. So charging the whole distance as rock
	 * is very nearly what a probe would have found. The two corrections applied on
	 * top are the refusal share above, and the climb, which is geometry and needs
	 * no terrain.
	 *
	 * @param blocks straight-line distance between the two veins
	 * @param rise net climb in blocks; zero or less costs nothing extra
	 * @param landable whether the destination has standable air against it -
	 *     false when that could not be determined either
	 */
	public static double estimatedHopSeconds(double blocks, int rise, boolean landable) {
		double seconds = blocks * DIG_SECONDS_PER_BLOCK / (1.0 - UNKNOWN_REFUSAL_SHARE);
		if (rise > 0) {
			seconds += climbSeconds(rise, landable);
		}
		return seconds;
	}

	/**
	 * What stopping at a vein costs before a single block is broken, in seconds.
	 *
	 * <p><b>Reported by the user 2026-08-26:</b> "some of them have not so many
	 * blocks in a vein." They were right and the cause is here. The old
	 * construction scored a candidate as value over what it adds to the walk, and
	 * for a vein sitting on the line the detour priced at zero - so the whole cost
	 * of taking it was {@link #mineSeconds}, which for a five-block vein is one
	 * break, 0.17 s. That is a divide by almost nothing, and the ratio it
	 * produced beat a 175-block prefab that had to pay for a three-second detour.
	 * The route filled up with trivial stops that happened to be on the way.
	 *
	 * <p>The 2026-08-27 nearest-first {@code Router} no longer scores by a ratio,
	 * so it cannot divide by a small cost - but this term is still charged, and
	 * still earns its place: it prices the stop itself into the budget, so a route
	 * of many tiny veins spends real time on each arrival rather than treating the
	 * stops as free once the coal is underfoot.
	 *
	 * <p>Nothing in the model was charging for the <i>stop itself</i>, and a stop
	 * is not free even when the coal is underfoot: you come off the tunnel line,
	 * find the faces, clear them, and pick the heading up again. One second is
	 * the conservative end of that, and it is enough to end the divide-by-zero -
	 * a five-block vein now has to beat about 4 coal per second rather than 30,
	 * which no on-the-way trinket does against a prefab.
	 *
	 * <p>Charged per stop, so it does not bias big veins against small ones on
	 * anything except the count of stops, which is exactly the term that was
	 * missing. Route -> Your mining speed in {@code /crg config} changes it.
	 */
	private static volatile double stopSeconds = 1.0;

	public static double stopSeconds() {
		return stopSeconds;
	}

	/** @param seconds the per-stop overhead; clamped to zero or more */
	public static void stopSeconds(double seconds) {
		stopSeconds = Math.max(0.0, seconds);
	}

	/**
	 * Seconds to clear a vein once you have arrived at it, including the cost of
	 * arriving.
	 *
	 * <p>Breaks, not blocks: see {@link #blocksPerBreak()}. Never less than one
	 * break, or a vein smaller than the spread would come out free.
	 *
	 * <p>{@link #stopSeconds()} is folded in here rather than added at the call
	 * sites on purpose: this is the one term every part of the solver already
	 * charges per stop - the fill's score, the budget in {@code Router.spent},
	 * and the route's reported minutes - so putting it here is what keeps them
	 * consistent.
	 */
	public static double mineSeconds(int coalBlocks) {
		return stopSeconds + Math.max(1.0, coalBlocks / blocksPerBreak) * SECONDS_PER_BREAK;
	}
}
