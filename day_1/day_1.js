import fs from "node:fs/promises";

const fileName = "input.txt";
const filePath = `/code/aoc/day_1/${fileName}`;

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

        // parse the number and add to sum
        sum += Number(cvalue);
    }

    console.log(sum);
}

// console.time("deciphering");
// decipher();
// console.timeEnd("deciphering");
const digitsMap = new Map([
    ["one", 1],
    ["two", 2],
    ["three", 3],
    ["four", 4],
    ["five", 5],
    ["six", 6],
    ["seven", 7],
    ["eight", 8],
    ["nine", 9],
]);

async function decipherPartTwo() {
    // read the data from our input file
    const data = await getInputData();

    // split the data string into an array
    const cvalues = data.split("\r\n");

    let sum = 0;
    let digitArr = [];

    for (let i = 0; i < cvalues.length; i++) {
        // extract the digit letters and values
        const regex = /\d|one|two|three|four|five|six|seven|eight|nine|/gi;
        const digits = cvalues[i].match(regex).filter((x) => x != "");

        // get the first and last digit
        let firstDigit = digits[0];
        let lastDigit = digits[digits.length - 1];

        let digitValue = "";
        if (digitsMap.has(firstDigit)) {
            digitValue += digitsMap.get(firstDigit);
        } else {
            digitValue += firstDigit;
        }

        if (digitsMap.has(lastDigit)) {
            digitValue += digitsMap.get(lastDigit);
        } else {
            digitValue += lastDigit;
        }

        digitArr.push(Number(digitValue));
    }

    for (let i = 0; i < digitArr.length; i++) {
        sum += digitArr[i];
        console.log(`Index: ${i}, Current Sum: ${sum} with a values ${digitArr[i]}`);
    }
}

console.time("deciphering");
decipherPartTwo();
console.timeEnd("deciphering");
