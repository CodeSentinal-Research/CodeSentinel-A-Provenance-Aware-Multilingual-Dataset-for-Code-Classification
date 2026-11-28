process.stdin.on('data', function(data) {
    var N = parseInt(data.toString().trim());
    var arr = [];
    process.stdin.once('data', function(data) {
        arr = data.toString().trim().split(' ').map(Number);
        var duplicates = arr.filter((val, index) => arr.indexOf(val) !== index);
        console.log(duplicates.join(' '));
    });
});