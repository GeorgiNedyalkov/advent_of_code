import fs from "fs";

function partOne(filePath) {
    const lines = fs.readFileSync(filePath, "utf-8").split("\r\n");

    const values = lines.map((line) => {
        const number1 = line.split("").find((v) => !Number.isNaN(Number(v)));
        const number2 = line.split("").findLast((v) => !Number.isNaN(Number(v)));

        return Number(number1 + number2);
    });

    return values.reduce((acc, v) => acc + v);
}

console.log(partOne("./input_malt.txt"));
