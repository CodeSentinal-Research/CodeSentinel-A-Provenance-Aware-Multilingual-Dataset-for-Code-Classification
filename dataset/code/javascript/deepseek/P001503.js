process.stdin.setEncoding('utf-8');

process.stdin.on('data', (data) => {
    let [N, K] = data.split(' ').map(x => parseInt(x, 10));

    const binaryArr = process.stdin.read().toString('utf-8').split('\n').slice(0, -1);

    let count = 0;
    let ones = [];

    for(let i = 0; i < N; i++) {
        if (binaryArr[i] === 1) {
            ones.push(i);
        }
    }

    let swaps = 0;

    for(let i = 0; i < ones.length; i++) {
        let currentIndex = ones[i];
        let left = currentIndex, right = currentIndex;

        while(left > 0 && binaryArr[left - 1] == 1) {
            left--;
        }

        while(right < N - 1 && binaryArr[right + 1] == 1) {
            right++;
        }

        let distance = right - currentIndex + 1;

        if(distance == K) {
            count++;
            swaps++;
            continue;
        }

        if(distance < K) {
            swaps += Math.floor((K - distance) / (K - 1));
            count += Math.floor((K - distance) / (K - 1));
            continue;
        }

        if(distance > K) {
            count += Math.floor(distance / K);
            swaps += Math.floor(distance / K) - 1;
            continue;
        }
    }

    console.log(swaps);
});