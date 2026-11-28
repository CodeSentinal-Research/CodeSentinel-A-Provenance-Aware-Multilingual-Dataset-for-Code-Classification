// print upper Triangular Matrix

function upperTriangularMatrix(matrix){
    console.log("Upper Triangular Matrix...");
    for(let i = 0; i < matrix.length; i++){
        let row = "";
        for(let j = 0; j < matrix.length; j++){
            if(i > j)
                row += "0 ";
            else
                row += matrix[i][j] + " ";
        }
        console.log(row);
    }
    
}

let matrix = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

upperTriangularMatrix(matrix);