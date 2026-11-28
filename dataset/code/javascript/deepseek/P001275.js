function minCostToHireWorkers(qualities, wages, K) {
    let workers = [];
    for (let i = 0; i < qualities.length; i++) {
        workers.push({quality: qualities[i], wage: wages[i], shortedWage: wages[i] / qualities[i]});
    }
    workers.sort((a, b) => a.shortedWage - b.shortedWage);
    
    let l = 0, r = qualities.length - 1;
    while (l < r) {
        if (workers[r].shortedWage < workers[r - 1].shortedWage) {
            workers[r - 1].shortedWage = workers[r].shortedWage + (workers[r].wage - workers[r].quality) / (K - (r - l));
            r--;
            K--;
        } else {
            workers[l].shortedWage = workers[l].wage / workers[l].quality;
            l++;
            K--;
        }
    }
    workers[l].shortedWage = workers[l].wage / workers[l].quality;

    return Math.min.apply(null, workers.map(w => w.shortedWage));
}

console.log(minCostToHireWorkers([4, 3, 1, 1], [20, 5, 1, 1], 3));