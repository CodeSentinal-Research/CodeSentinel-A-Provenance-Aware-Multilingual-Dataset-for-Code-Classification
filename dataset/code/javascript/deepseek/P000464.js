function findClosestElement() {
    var N = parseInt(readline());
    var target = parseInt(readline());
    var numbers = readline().split(' ');
    var closest = parseInt(numbers[0]);
    var diff = Math.abs(target - closest);

    for (var i = 1; i < N; i++) {
        var num = parseInt(numbers[i]);
        var currentDiff = Math.abs(target - num);
        if (currentDiff < diff) {
            diff = currentDiff;
            closest = num;
        }
    }

    print(closest);
}