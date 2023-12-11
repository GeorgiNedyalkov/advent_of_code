const fs = require("node:fs/promises");

const fileName = "input.txt";
const filePath = `/code/aoc/${fileName}`;

// get input data from files
async function getInputData() {
    try {
        const data = await fs.readFile(filePath, { encoding: "utf-8" });
        return data;
    } catch (error) {
        console.log(error);
    }
}

async function decipher() {
    // read the data from our input file
    const data = await getInputData();

    // split the data string into an array
    const cvalues = data.split("\r\n");

    let sum = 0;
    // iterate through all values
    for (let i = 0; i < cvalues.length; i++) {
        let cvalue = "";
        // starting from the beginning look for the first digit
        for (let j = 0; j < cvalues[i].length; j++) {
            // check if the character is a number: if !isNaN returns true
            if (!isNaN(cvalues[i][j])) {
                cvalue += cvalues[i][j];
                break;
            }
        }

        // starting from the end look for the last digit
        for (let k = cvalues[i].length; k > 0; k--) {
            if (!isNaN(cvalues[i][k])) {
                cvalue += cvalues[i][k];
                break;
            }
        }

        // check to see if cvalue has a length of one if so add it to itself
        if (cvalue.length == 1) {
            cvalue += cvalue;
        }

        console.log(cvalue);

        // parse the number and add to sum
        sum += Number(cvalue);
    }

    console.log(sum);
}

console.time("deciphering");
decipher();
console.timeEnd("deciphering");
