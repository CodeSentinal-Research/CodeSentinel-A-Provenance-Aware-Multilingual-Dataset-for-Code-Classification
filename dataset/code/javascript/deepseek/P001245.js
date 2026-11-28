function reconstructQueue(people) {
    let idx = {};
    let queue = [];
    for(let p of people){
        if(!idx[p[0]]) idx[p[0]] = [];
        idx[p[0]].push(p[1]);
    }
    for(let h = 1; h <= people.length; h++){
        if(idx[h]){
            for(let c of idx[h]){
                queue.push(h, c);
            }
        }
        else queue.push(h, 0);
    }
    return queue;
}
This JavaScript function takes an array of people with their height and the count of people in front with height greater than or equal to theirs. It creates an index of people with their height, then for each height, it adds the count of people in front with height greater than or equal to theirs to the queue.