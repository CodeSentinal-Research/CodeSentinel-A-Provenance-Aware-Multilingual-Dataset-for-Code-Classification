function digitFrequencyCounter(n) {
    const counter = new Array(10).fill(0);

    String(n).split('').forEach(digit => {
        counter[digit]++;
    });

    return counter;
}