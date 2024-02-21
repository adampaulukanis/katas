/*
 * Define constants first
 */
const HOW_MANY_ITERATIONS = 6;
const RCHANCE = 0.5;
const SIZEX = process.stdout.columns;
const SIZEY = process.stdout.rows;

let grid = [
    [ 0, 0, 0 ],
    [ 0, 0, 0 ],
    [ 0, 0, 0 ],
];

class Grid {
    constructor(sizeX, sizeY, fill = 0) {
        this.sizeX = sizeX;
        this.sizeY = sizeY;
        this.grid = new Array(sizeY).fill().map(row => new Array(sizeX).fill(fill));
    }

    isInside(x, y) {
        return (x >= 0 && x < this.grid.length && y >= 0 && y < this.grid[0].length);
    }
}

function draw(grid) {
    const g = grid.grid;
    console.log("-------------- New Generation -----------------");
    for (let y = 0; y < g.length; y++) {
        let line = [];
        for (let x = 0; x < g[0].length; x++) {
            let cell = g[y][x];
            line.push(cell ? '█' : ' ');
        }
        console.log(line.join("").toString());
    }
}

function nextGen(grid) {
    const g = grid.grid;
    let newG = new Grid(grid.sizeX, grid.sizeY);
    for (let y = 0 + 1; y < g.length - 1; y++) {
        for (let x = 0 + 1; x < g[0].length - 1; x++) {
            let sum = 0;
            sum += g[y - 1][x - 1];
            sum += g[y - 1][x    ];
            sum += g[y - 1][x + 1];
            sum += g[y    ][x - 1];
            sum += g[y    ][x + 1];
            sum += g[y + 1][x - 1];
            sum += g[y + 1][x    ];
            sum += g[y + 1][x + 1];

            let cell = g[y][x];
            let next = newG.grid;
            if (cell == 0 && sum === 3) {
                next[y][x] = 1;
            } else if (cell == 1 && (sum < 2 || sum > 3)) {
                next[y][x] = 0;
            } else {
                next[y][x] = cell;
            }
        }
    }

    return newG;
}

let g = new Grid(SIZEX, SIZEY);

// Randomize
for (let y = 0; y < g.grid.length; y++) {
    for (let x = 0; x < g.grid[0].length; x++) {
        //g.grid[y][x] = Math.round(Math.random()); // not sure about Math thing
        g.grid[y][x] = Math.random() > RCHANCE ? 1 : 0;
    }
}

// ###################################################################

draw(g);

/*
for (let i = 0; i < HOW_MANY_ITERATIONS; i++) {
    console.log("-------- New Generation -----------");
    g = nextGen(g);
    draw(g);
}
*/

setInterval(() => {
    g = nextGen(g);
    draw(g);
}, 1000);
