package jeff.coalroutegenerator.client.telemetry;

import java.util.function.Consumer;

/**
 * One airborne stretch, from leaving the ground to landing again.
 *
 * <p><b>This is the unit the climb cost is really made of.</b> The cost model
 * used to charge climbing as "dig a foothold and teleport onto it, every three
 * blocks", which described something the user does not do. What they do, given
 * 2026-08-26: mine with Jump Boost IV, look steeply but not vertically upward,
 * dig a diagonal tunnel, and hold jump - "so when I mine and hold jump I can
 * hopefully ascend 5 blocks at a time. But sometimes it fails."
 *
 * <p>Two things follow, and both are why this class records a shape rather than
 * a rate.
 *
 * <ul>
 * <li><b>Climb cost is quantised.</b> One jump buys whatever it buys whether you
 *     needed one block of rise or five, so a vein one block above your head costs
 *     a whole cycle. A seconds-per-block-of-rise number cannot express that.
 * <li><b>The rise a cycle buys is a distribution, not a constant.</b> The user,
 *     correcting the first draft of this design: "sometimes I will fail to get
 *     exactly 5 blocks high, I might miss my jump and get like 3 blocks high or
 *     4 or something, or sometimes I'll fail entirely." A mean would hide the
 *     tail, and the tail is the entire reason veins overhead are unpleasant. So
 *     every cycle is logged with its own net rise and the report prints the
 *     histogram.
 * </ul>
 *
 * <p>The number of cycles needed to climb a given height is therefore a renewal
 * process over that histogram, not a division by an average. Deriving the
 * eventual cost function from it is deliberately left to the person reading the
 * data; this class only makes sure the data can answer the question.
 *
 * <p><b>A cycle failed when it ended at or below the height it started at.</b>
 * That was the user's choice of test on 2026-08-26, over the alternative that
 * also counts re-jumping from the same ledge. It cannot mistake a deliberate
 * two-stage climb for a failure, and it catches both falling back down and not
 * clearing the lip.
 */
public final class AirCycles {
	/**
	 * One completed airborne stretch.
	 *
	 * @param index counting from zero within the session
	 * @param startMs when the player left the ground, ms since session start
	 * @param endMs when they landed
	 * @param launchY the y they left from
	 * @param peakY the highest y reached in the air
	 * @param landY the y they landed at
	 * @param horizontal ground distance covered between launch and landing
	 * @param path total distance travelled in the air, which exceeds
	 *     {@code horizontal} on any arc and is what says whether the cycle was a
	 *     climb along a tunnel or a drop down a shaft
	 * @param digTicks ticks in the air with the attack button held. A diagonal
	 *     jump tunnel is nearly all of them; a fall down an open shaft is none,
	 *     and that difference is the cheapest way to tell the two apart
	 * @param jumpHeldTicks ticks with jump held, which on a Jump Boost ascent is
	 *     most of the cycle and on a fall is usually zero
	 * @param coalBreaks coal that vanished during the cycle
	 * @param jumpAmp the Jump Boost level in effect, one-based, or zero for none
	 * @param avgPing mean latency over the cycle, in ms
	 * @param hop which hop this cycle belonged to, or -1
	 */
	public record Cycle(int index, double startMs, double endMs, double launchY, double peakY,
			double landY, double horizontal, double path, int digTicks, int jumpHeldTicks,
			int coalBreaks, int jumpAmp, double avgPing, int hop) {
		public double seconds() {
			return (endMs - startMs) / 1000.0;
		}

		/** What the cycle actually bought, in blocks of height. Negative is a drop. */
		public double netRise() {
			return landY - launchY;
		}

		/** How high it got, which exceeds {@link #netRise()} on any failed attempt. */
		public double peakRise() {
			return peakY - launchY;
		}

		/** Ended no higher than it began. See the class note on why this is the test. */
		public boolean failed() {
			return netRise() <= 0.0;
		}

		/**
		 * A cycle that was an attempt to gain height rather than a drop or a
		 * flat hop. Used only for reporting; the raw rows keep everything.
		 */
		public boolean ascent() {
			return peakRise() >= MIN_ASCENT_RISE && (digTicks > 0 || jumpHeldTicks > 0);
		}
	}

	/**
	 * How high a cycle has to reach before the report calls it an ascent
	 * attempt. Below this it is a step over a lip or a stumble, and pooling
	 * those with real jumps would drag the measured cycle rise towards zero.
	 * A Jump Boost IV jump clears well over a block, so this excludes nothing
	 * the player meant as a climb.
	 */
	public static final double MIN_ASCENT_RISE = 1.2;

	private final Consumer<Cycle> sink;

	private boolean airborne;
	private int index;

	private double startMs;
	private double launchY;
	private double peakY;
	private double launchX;
	private double launchZ;
	private double path;
	private int digTicks;
	private int jumpHeldTicks;
	private int coalBreaks;
	private int jumpAmp;
	private double pingSum;
	private int pingTicks;
	private int hop;

	public AirCycles(Consumer<Cycle> sink) {
		this.sink = sink;
	}

	/**
	 * Feeds one sampled tick.
	 *
	 * @param ms ms since session start
	 * @param onGround whether the player is standing on something this tick
	 * @param step distance moved since the previous sample
	 * @param attack whether the attack button is down
	 * @param jumpHeld whether the jump key is down
	 * @param coal coal blocks that vanished on this tick
	 */
	public void tick(double ms, double x, double y, double z, boolean onGround, double step,
			boolean attack, boolean jumpHeld, int coal, int jumpAmplifier, int ping, int hopIndex) {
		if (!onGround) {
			if (!airborne) {
				airborne = true;
				startMs = ms;
				launchY = y;
				peakY = y;
				launchX = x;
				launchZ = z;
				path = 0.0;
				digTicks = 0;
				jumpHeldTicks = 0;
				coalBreaks = 0;
				jumpAmp = jumpAmplifier;
				pingSum = 0.0;
				pingTicks = 0;
				hop = hopIndex;
			}
			peakY = Math.max(peakY, y);
			path += step;
			if (attack) {
				digTicks++;
			}
			if (jumpHeld) {
				jumpHeldTicks++;
			}
			coalBreaks += coal;
			// The highest level seen during the cycle: a potion that lapses
			// mid-jump still bought this jump its height.
			jumpAmp = Math.max(jumpAmp, jumpAmplifier);
			pingSum += ping;
			pingTicks++;
			return;
		}

		if (airborne) {
			airborne = false;
			double dx = x - launchX;
			double dz = z - launchZ;
			sink.accept(new Cycle(index++, startMs, ms, launchY, peakY, y,
					Math.sqrt(dx * dx + dz * dz), path, digTicks, jumpHeldTicks, coalBreaks,
					jumpAmp, pingTicks == 0 ? 0.0 : pingSum / pingTicks, hop));
		}
	}

	/**
	 * Abandons an in-flight cycle without emitting it.
	 *
	 * <p>A warp or a death lands the player somewhere unrelated to where they
	 * jumped from, and the net rise of that is meaningless.
	 */
	public void abandon() {
		airborne = false;
	}

	public boolean airborne() {
		return airborne;
	}

	public int count() {
		return index;
	}
}
