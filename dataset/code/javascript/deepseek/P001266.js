process.stdin.resume();
process.stdin.on('data', function(data){
    var input = data.toString().trim().split("\n");
    var N = parseInt(input[0]);
    var K = parseInt(input[1]);
    var InitialCapital = parseFloat(input[2]);
    var projects = [];
    for(var i = 3; i < input.length; i++){
        var project = input[i].split(" ");
        projects.push({
            requiredCapital: parseFloat(project[0]),
            profit: parseFloat(project[1])
        });
    }
    projects.sort(function(a, b){
        return b.profit - a.profit || a.requiredCapital - b.requiredCapital
    });
    function maxFinalCapital(projects, K, InitialCapital){
        var finalCapital = InitialCapital;
        for(var i = 0; i < projects.length && K > 0; i++){
            if(finalCapital >= projects[i].requiredCapital){
                finalCapital += projects[i].profit;
                K--;
            }
        }
        return finalCapital;
    }
    console.log(maxFinalCapital(projects, K, InitialCapital));
});