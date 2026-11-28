function dungeonGame() {
    const readline = require('readline');

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question('Enter the number of rows (R): ', (R) => {
        rl.question('Enter the number of columns (C): ', (C) => {
            const dungeon = [];
            for (let i = 0; i < R; i++) {
                dungeon[i] = [];
                rl.question(`Enter ${C} numbers for row ${i + 1}: `, (row) => {
                    dungeon[i] = row.split(' ').map(Number);
                    let minHealth = Math.max(...dungeon[i]);
                    console.log(minHealth);
                    rl.close();
                });
            }
        });
    });
}

dungeonGame();