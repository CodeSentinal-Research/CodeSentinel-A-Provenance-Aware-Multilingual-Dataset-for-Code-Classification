// Generates a tiny heap dump with object shapes the parser tests assert against.
//
// Every count here is a constant, and the Rust tests assert those exact numbers.  If you change a
// count, change docs/phases/01-parser.md and the tests with it.
//
// The shapes deliberately cover the traps in SPEC.md section 5.5:
//   - a three-deep inheritance chain, so instance field order can be checked
//   - strings, which differ between JDK 8 and JDK 9+
//   - one array of every primitive type, including a zero-length one
//   - a string holding a NUL and a supplementary character, for the modified UTF-8 decoder
//   - a reference cycle and a diamond, for the graph phases

import com.sun.management.HotSpotDiagnosticMXBean;
import java.lang.management.ManagementFactory;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

public final class Fixture {

    public static final int LEAF_COUNT = 1000;
    public static final int MID_COUNT = 500;
    public static final int NODE_COUNT = 250;

    static class Leaf {
        int leafInt;
        long leafLong;
    }

    static class Mid extends Leaf {
        String midString;
        boolean midFlag;
    }

    static class Node extends Mid {
        Object[] children;
        Node next;
    }

    static final class Arrays {
        byte[] bytes = new byte[1024];
        char[] chars = new char[512];
        int[] ints = new int[256];
        long[] longs = new long[128];
        short[] shorts = new short[64];
        float[] floats = new float[32];
        double[] doubles = new double[16];
        boolean[] booleans = new boolean[8];
        byte[] empty = new byte[0];
    }

    // A static field, so everything below stays reachable from a GC root.
    static final List<Object> KEEP_ALIVE = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        if (args.length != 1) {
            System.err.println("usage: Fixture <output.hprof>");
            System.exit(2);
        }

        for (int i = 0; i < LEAF_COUNT; i++) {
            Leaf leaf = new Leaf();
            leaf.leafInt = i;
            leaf.leafLong = (long) i * 1000000L;
            KEEP_ALIVE.add(leaf);
        }

        for (int i = 0; i < MID_COUNT; i++) {
            Mid mid = new Mid();
            mid.leafInt = i;
            mid.midString = "heapduck-fixture-" + i;
            mid.midFlag = (i % 2) == 0;
            KEEP_ALIVE.add(mid);
        }

        List<Node> nodes = new ArrayList<>();
        for (int i = 0; i < NODE_COUNT; i++) {
            Node node = new Node();
            node.leafInt = i;
            node.midString = "node-" + i;
            node.children = new Object[3];
            nodes.add(node);
            KEEP_ALIVE.add(node);
        }

        // A three-node cycle.
        nodes.get(0).next = nodes.get(1);
        nodes.get(1).next = nodes.get(2);
        nodes.get(2).next = nodes.get(0);

        // A diamond: two parents share one child.
        Object shared = new Leaf();
        nodes.get(10).children[0] = shared;
        nodes.get(11).children[0] = shared;
        KEEP_ALIVE.add(shared);

        KEEP_ALIVE.add(new Arrays());

        // Built from parts so the source file stays plain ASCII.
        String tricky = "nul" + ((char) 0) + " astral "
                + new String(Character.toChars(0x1F600)) + " end";
        KEEP_ALIVE.add(tricky);

        Path out = Path.of(args[0]).toAbsolutePath();
        Files.createDirectories(out.getParent());
        Files.deleteIfExists(out);

        HotSpotDiagnosticMXBean bean =
                ManagementFactory.getPlatformMXBean(HotSpotDiagnosticMXBean.class);
        bean.dumpHeap(out.toString(), true);

        System.out.println("wrote " + out + " (" + Files.size(out) + " bytes)");
    }
}
